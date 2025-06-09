#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quan-li-nhan-vien.cpp"
#include "quan-li-cong-viec.cpp"

void phan_cong_cong_viec() {
    if (soLuongCongViec == 0 || soLuongNhanVien == 0) {
        printf("Không thể phân công! Chưa có công việc hoặc nhân viên.\n");
        return;
    }

    printf("\n--- DANH SÁCH CÔNG VIỆC CHƯA GIAO ---\n");
    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].trangThai == -1) { // Chưa hoàn thành = chưa giao
            printf("ID: %d - %s\n", danhSachCongViec[i].id, danhSachCongViec[i].ten);
        }
    }

    printf("\n--- DANH SÁCH NHÂN VIÊN ---\n");
    for (int i = 0; i < soLuongNhanVien; i++) {
        printf("ID: %d - %s\n", danhSachNhanVien[i].id, danhSachNhanVien[i].ten);
    }

    int maCongViec, maNhanVien;
    printf("\nNhập ID công việc cần giao: ");
    scanf("%d", &maCongViec);
    printf("Nhập ID nhân viên nhận công việc: ");
    scanf("%d", &maNhanVien);

    int timThayCV = 0, timThayNV = 0;

    // Tìm công việc
    for (int i = 0; i < soLuongCongViec; i++) {
        if (danhSachCongViec[i].id == maCongViec) {
            timThayCV = 1;
            // Gán trạng thái là "Đã hoàn thành" giả lập là "đã phân"
            danhSachCongViec[i].trangThai = 1;
            break;
        }
    }

    // Tìm nhân viên
    for (int i = 0; i < soLuongNhanVien; i++) {
        if (danhSachNhanVien[i].id == maNhanVien) {
            timThayNV = 1;
            break;
        }
    }

    if (timThayCV && timThayNV) {
        printf(">> Đã phân công công việc thành công!\n");
    } else {
        printf(">> Phân công thất bại! Kiểm tra lại ID công việc hoặc ID nhân viên.\n");
    }
}
