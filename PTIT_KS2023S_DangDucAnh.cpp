#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SinhVien {
	int id;
	char name[50];
	char birthday[50];
	char address[100];
	int status; 
} sv;

void printfMenu() {
	printf("***********MENU**********\n");
	printf("1. In toan bo danh sach sinh vien trong cung 1 hang\n");
	printf("2. Them sinh vien\n");	
	printf("3. Cap nhat thong tin sinh vien\n");
	printf("4. Nhap ten sinh vien muon xoa\n");
	printf("5. Sap xep studentList theo id\n");
	printf("6. Tim kiem theo ten sinh vien\n");
	printf("7. Tim kiem va in ra thong tin sinh vien theo status\n");
	printf("8. Thoat\n");
	printf("Lua chon cua ban la: ");
}

void nhap_thong_tin(sv *studentList, int *n) {
	for(int i = 0; i < *n; i++) {
		printf("Nhap ma sinh vien: ");
		scanf("%d", &studentList[i].id);
		printf("Nhap ten sinh vien: ");
		scanf("%s", studentList[i].name);
		printf("Nhap ngay/ thang/ nam sinh: ");
		scanf("%s", studentList[i].birthday);
		printf("Nhap dia chi cua sinh vien: ");
		scanf("%s", studentList[i].address);
		printf("Nhap trang thai cua sinh vien (0 hoac 1): ");
		scanf("%d", &studentList[i].status);
	}
}

void in_thong_tin(sv *studentList, int *n) {
	for(int i = 0; i < *n; i++) {
		printf("Sinh vien %d: ", i + 1);
		printf("Id: %d", studentList[i].id);
		printf("Ten: %s", studentList[i].name);
		printf("Ngay sinh: %s", studentList[i].birthday);
		printf("Dia chi: %s", studentList[i].address);
		printf("Status: %d", studentList[i].status);
		printf("\n");
	}
}

void them_thong_tin(sv *studentList, int *n) {
	printf("Nhap ma sinh vien: ");
	scanf("%d", &studentList[*n].id);
	printf("Nhap ten sinh vien: ");
	scanf("%s", studentList[*n].name);
	printf("Nhap ngay/ thang/ nam sinh: ");
	scanf("%s", studentList[*n].birthday);
	printf("Nhap dia chi cua sinh vien: ");
	scanf("%s", studentList[*n].address);
	printf("Nhap trang thai cua sinh vien: ");
	scanf("%d", &studentList[*n].status);
	(*n)++;
}

void cap_nhat_thong_tin(sv *studentList, int *n) {
	char updateName[50];
	int x = 0;
	printf("Nhap vao ten sinh vien: ");
	scanf("%s", updateName);
	for(int i = 0; i < *n; i++) {
		if(strcmp(studentList[i].name, updateName) == 0) {
			printf("Nhap ma sinh vien: ");
			scanf("%d", &studentList[i].id);
			printf("Nhap ten sinh vien: ");
			scanf("%s", studentList[i].name);
			printf("Nhap ngay/ thang/ nam sinh: ");
			scanf("%s", studentList[i].birthday);
			printf("Nhap dia chi cua sinh vien: ");
			scanf("%s", studentList[i].address);
			printf("Nhap trang thai cua sinh vien: ");
			scanf("%d", &studentList[i].status);
			x = 1;
		}
	}
	if(x == 1) {
		printf("Cap nhat thong tin thanh cong\n");
	} else {
		printf("Khong tim thay sinh vien\n");
	}
}

void xoa_thong_tin(sv *studentList, int *n) {
	char deleteName[50];
	printf("Nhap vao ten sinh vien: ");
	scanf("%s", deleteName);
	for(int i = 0; i < *n; i++) {
		if(strcmp(studentList[i].name, deleteName) == 0) {
			for(int j = i; j < *n - 1; j++) {
				studentList[j] = studentList[j+1];
			}
			(*n)--;
			break;
		}
	}
}

void sap_xep_id(sv *studentList,int *n) {
	for(int i = 0; i < *n - 1; i++) {
		for(int j = i + 1; j < *n; j++) {
			if(studentList[i].id > studentList[j].id) {
				sv temp = studentList[i];
				studentList[i] = studentList[j];
				studentList[j] = temp;
			}
		}
	}
	printf("Da sap xep danh sach sinh vien theo id\n");
}

void tim_kiem_ten(sv *studentList, int *n) {
	char searchName[50];
	int left = 0;
	int right = *n - 1;
	printf("Nhap vao ten sinh vien can tim: ");
	scanf("%s", searchName);
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(strcmp(studentList[mid].name, searchName) == 0) {
			printf("Thong tin sinh vien can tim:\n");
			printf("Id: %d\n", studentList[mid].id);
			printf("Ten: %s\n", studentList[mid].name);
			printf("Ngay sinh: %s\n", studentList[mid].birthday);
			printf("Dia chi: %s\n", studentList[mid].address);
			printf("Status: %d\n", studentList[mid].status);
			return;
		}
		else if(strcmp(studentList[mid].name, searchName) < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("Khong tim thay sinh vien\n");
}

void tim_kiem_status(sv *studentList, int *n) {
	int searchStatus;
	printf("Nhap vao trang thai sinh vien can tim: ");
	scanf("%d", &searchStatus);
	printf("Thong tin sinh vien theo status %d:\n", searchStatus);
	for(int i = 0; i < *n; i++) {
		if(studentList[i].status == searchStatus) {
			printf("Id: %d\n", studentList[i].id);
			printf("Ten: %s\n", studentList[i].name);
			printf("Ngay sinh: %s\n", studentList[i].birthday);
			printf("Dia chi: %s\n", studentList[i].address);
			printf("Status: %d\n", studentList[i].status);
			printf("\n");
		}
	}
}

int main() {
	sv studentList[100];
	int n = 0;
	int choice;
	do {
		printfMenu();
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				in_thong_tin(studentList, &n);
				break;
			case 2:
				them_thong_tin(studentList, &n);
				break;
			case 3:
				cap_nhat_thong_tin(studentList, &n);
				break;
			case 4:
				xoa_thong_tin(studentList, &n);
				break;
			case 5:
				sap_xep_id(studentList, &n);
				break;
			case 6:
				tim_kiem_ten(studentList, &n);
				break;
			case 7:
				tim_kiem_status(studentList, &n);
				break;
			case 8:
				printf("Thoat chuong trinh\n");
				break;
			default:
				printf("Lua chon khong hop le\n");
				break;
		}
	} while(choice != 8);

	return 0;
}
