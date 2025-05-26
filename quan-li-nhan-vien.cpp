#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NHAN_VIEN 100

typedef struct {
    int id;
    char ten[50];
    char viTri[50];
} NhanVien;

NhanVien danhSachNhanVien[MAX_NHAN_VIEN];
int soLuongNhanVien = 0;

// --- Các chức năng quản lý nhân viên ---
void themNhanVien() {
    if (soLuongNhanVien >= MAX_NHAN_VIEN) {
        printf(">> Danh sách nhân viên đã đầy!\n");
        return;
    }
    NhanVien nv;
    nv.id = soLuongNhanVien + 1;
    printf("Nhập tên nhân viên: ");
    scanf(" %49[^\n]", nv.ten);
    printf("Nhập vị trí: ");
    scanf(" %49[^\n]", nv.viTri);
    danhSachNhanVien[soLuongNhanVien++] = nv;
    printf(">> Đã thêm nhân viên: %s, Vị trí: %s\n", nv.ten, nv.viTri);
}

void hienThiNhanVien() {
    printf("\n--- Danh sách nhân viên ---\n");
    if (soLuongNhanVien == 0) {
        printf("Chưa có nhân viên nào.\n");
        return;
    }
    for (int i = 0; i < soLuongNhanVien; i++) {
        printf("ID: %d, Tên: %s, Vị trí: %s\n", danhSachNhanVien[i].id, danhSachNhanVien[i].ten, danhSachNhanVien[i].viTri);
    }
}

void xoaNhanVien() {
    int id;
    printf("Nhập ID nhân viên cần xóa: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < soLuongNhanVien; i++) {
        if (danhSachNhanVien[i].id == id) {
            found = 1;
            for (int j = i; j < soLuongNhanVien - 1; j++) {
                danhSachNhanVien[j] = danhSachNhanVien[j + 1];
            }
            soLuongNhanVien--;
            printf(">> Đã xóa nhân viên ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Không tìm thấy nhân viên với ID %d\n", id);
}

void quanLyNhanVien() {
    int choice;
    do {
        printf("\n--- QUẢN LÝ NHÂN VIÊN ---\n");
        printf("1. Thêm nhân viên\n");
        printf("2. Hiển thị danh sách nhân viên\n");
        printf("3. Xóa nhân viên\n");
        printf("0. Quay lại menu chính\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            themNhanVien();
            break;
        case 2:
            hienThiNhanVien();
            break;
        case 3:
            xoaNhanVien();
            break;
        case 0:
            printf("Quay lại menu chính...\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ, vui lòng thử lại.\n");
        }
    } while (choice != 0);
}

