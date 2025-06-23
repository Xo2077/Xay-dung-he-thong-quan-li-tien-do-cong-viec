#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONG_VIEC 100

typedef struct {
    int id;
    char ten[50];
    char moTa[100];
    int trangThai; // -1: Chua co nguoi phu trach, 0: Chua hoan thanh, 1: Da hoan thanh
} CongViec;

CongViec danhSachCongViec[MAX_CONG_VIEC];
int soLuongCongViec = 0;

void themCongViec() {
    if (soLuongCongViec >= MAX_CONG_VIEC) {
        printf(">> Danh sach cong viec da day!\n");
        return;
    }
    CongViec cv;
    cv.id = soLuongCongViec + 1;
    printf("Nhap ten cong viec: ");
    scanf(" %49[^\n]", cv.ten);
    printf("Nhap mo ta cong viec: ");
    scanf(" %99[^\n]", cv.moTa);
    cv.trangThai = -1; // Mac dinh: chua co nguoi phu trach
    danhSachCongViec[soLuongCongViec++] = cv;
    printf(">> Da them cong viec: %s\n", cv.ten);
}

void hienThiCongViec() {
    printf("\n--- Danh sach cong viec ---\n");
    if (soLuongCongViec == 0) {
        printf("Chua co cong viec nao.\n");
        return;
    }

    for (int i = 0; i < soLuongCongViec; i++) {
        const char* trangThaiStr;
        if (danhSachCongViec[i].trangThai == -1)
            trangThaiStr = "Chua co nguoi phu trach";
        else if (danhSachCongViec[i].trangThai == 0)
            trangThaiStr = "Chua hoan thanh";
        else
            trangThaiStr = "Da hoan thanh";

        printf("ID: %d, Ten: %s, Mo ta: %s, Trang thai: %s\n",
               danhSachCongViec[i].id,
               danhSachCongViec[i].ten,
               danhSachCongViec[i].moTa,
               trangThaiStr);
    }
}

void capNhatTrangThaiCongViec() {
    int id, trangThai;
    printf("Nhap ID cong viec can cap nhat trang thai: ");
    scanf("%d", &id);
    printf("Nhap trang thai (0: Chua hoan thanh, 1: Da hoan thanh): ");
    scanf("%d", &trangThai);
    int found = 0;

    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == id) {
            danhSachCongViec[i].trangThai = (trangThai == 1) ? 1 : 0;
            found = 1;
            printf(">> Da cap nhat trang thai cong viec ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Khong tim thay cong viec voi ID %d\n", id);
}

void xoaCongViec() {
    int id;
    printf("Nhap ID cong viec can xoa: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == id) {
            found = 1;
            for (int j = i; j < soLuongCongViec - 1; j++) {
                danhSachCongViec[j] = danhSachCongViec[j + 1];
            }
            soLuongCongViec--;
            printf(">> Da xoa cong viec ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Khong tim thay cong viec voi ID %d\n", id);
}

void luuCongViec() {
    FILE *f = fopen("cv.txt", "w");
    if (f == NULL) {
        printf(">> Loi: Khong the mo file de ghi!\n");
        return;
    }

    for (int i = 0; i < soLuongCongViec; i++) {
        fprintf(f, "%d\n", danhSachCongViec[i].id);
        fprintf(f, "%s\n", danhSachCongViec[i].ten);
        fprintf(f, "%s\n", danhSachCongViec[i].moTa);
        fprintf(f, "%d\n", danhSachCongViec[i].trangThai);
    }
    fclose(f);
    printf(">> Da luu cong viec vao file cv.txt\n");
}

void quanLyCongViec() {
    int luaChon;
    do {
        printf("\n--- QUAN LY CONG VIEC ---\n");
        printf("1. Them cong viec\n");
        printf("2. Hien thi danh sach cong viec\n");
        printf("3. Cap nhat trang thai cong viec\n");
        printf("4. Xoa cong viec\n");
        printf("5. Luu cong viec vao file\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1: themCongViec(); break;
            case 2: hienThiCongViec(); break;
            case 3: capNhatTrangThaiCongViec(); break;
            case 4: xoaCongViec(); break;
            case 5: luuCongViec(); break;
            case 0: printf("Thoat chuong trinh...\n"); break;
            default: printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 0);
}

