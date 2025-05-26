#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONG_VIEC 100

typedef struct {
    int id;
    char ten[50];
    char moTa[100];
    int trangThai; // 0: Chưa hoàn thành, 1: Đã hoàn thành
} CongViec;

CongViec danhSachCongViec[MAX_CONG_VIEC];
int soLuongCongViec = 0;

// --- Các chức năng quản lý công việc ---
void themCongViec() {
    if (soLuongCongViec >= MAX_CONG_VIEC) {
        printf(">> Danh sách công việc đã đầy!\n");
        return;
    }
    CongViec cv;
    cv.id = soLuongCongViec + 1;
    printf("Nhập tên công việc: ");
    scanf(" %49[^\n]", cv.ten);
    printf("Nhập mô tả công việc: ");
    scanf(" %99[^\n]", cv.moTa);
    cv.trangThai = 0; // Mặc định chưa hoàn thành
    danhSachCongViec[soLuongCongViec++] = cv;
    printf(">> Đã thêm công việc: %s\n", cv.ten);
}

void hienThiCongViec() {
    printf("\n--- Danh sách công việc ---\n");
    if (soLuongCongViec == 0) {
        printf("Chưa có công việc nào.\n");
        return;
    }
    for (int i = 0; i < soLuongCongViec; i++) {
        printf("ID: %d, Tên: %s, Mô tả: %s, Trạng thái: %s\n",
               danhSachCongViec[i].id,
               danhSachCongViec[i].ten,
               danhSachCongViec[i].moTa,
               danhSachCongViec[i].trangThai == 0 ? "Chưa hoàn thành" : "Đã hoàn thành");
    }
}

void capNhatTrangThaiCongViec() {
    int id, trangThai;
    printf("Nhập ID công việc cần cập nhật trạng thái: ");
    scanf("%d", &id);
    printf("Nhập trạng thái (0: Chưa hoàn thành, 1: Đã hoàn thành): ");
    scanf("%d", &trangThai);
    int found = 0;
    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == id) {
            danhSachCongViec[i].trangThai = (trangThai == 1) ? 1 : 0;
            found = 1;
            printf(">> Đã cập nhật trạng thái công việc ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Không tìm thấy công việc với ID %d\n", id);
}

void xoaCongViec() {
    int id;
    printf("Nhập ID công việc cần xóa: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == id) {
            found = 1;
            for (int j = i; j < soLuongCongViec - 1; j++) {
                danhSachCongViec[j] = danhSachCongViec[j + 1];
            }
            soLuongCongViec--;
            printf(">> Đã xóa công việc ID %d\n", id);
            break;
        }
    }
    if (!found)
        printf(">> Không tìm thấy công việc với ID %d\n", id);
}

void quanLyCongViec() {
    int choice;
    do {
        printf("\n--- QUẢN LÝ CÔNG VIỆC ---\n");
        printf("1. Thêm công việc\n");
        printf("2. Hiển thị danh sách công việc\n");
        printf("3. Cập nhật trạng thái công việc\n");
        printf("4. Xóa công việc\n");
        printf("0. Quay lại menu chính\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                themCongViec();
                break;
            case 2:
                hienThiCongViec();
                break;
            case 3:
                capNhatTrangThaiCongViec();
                break;
            case 4:
                xoaCongViec();
                break;
            case 0:
                printf("Quay lại menu chính...\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ, vui lòng thử lại.\n");
        }
    } while (choice != 0);
}
