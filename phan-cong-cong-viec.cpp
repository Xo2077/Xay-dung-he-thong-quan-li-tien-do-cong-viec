#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<
void phan_cong_cong_viec() {
    if (so_luong_cong_viec >= MAX_TASKS || so_luong_nhan_vien == 0) {
        printf("Không thể phân công! Danh sách đầy hoặc chưa có nhân viên.\n");
        return;
    }

    printf("\n--- CÔNG VIỆC CHƯA GIAO ---\n");
    for (int i = 0; i < so_luong_cong_viec; i++) {
        if (danh_sach_cong_viec[i].nguoi_phu_trach == -1) {
            printf("%d. %s\n", danh_sach_cong_viec[i].ma_so, danh_sach_cong_viec[i].mo_ta);
        }
    }

    printf("\n--- DANH SÁCH NHÂN VIÊN ---\n");
    for (int i = 0; i < so_luong_nhan_vien; i++) {
        printf("%d. %s\n", danh_sach_nhan_vien[i].ma_so, danh_sach_nhan_vien[i].ho_ten);
    }

    int ma_cong_viec, ma_nhan_vien;
    printf("\nNhập mã công việc cần giao: ");
    scanf("%d", &ma_cong_viec);
    printf("Nhập mã nhân viên: ");
    scanf("%d", &ma_nhan_vien);

    bool tim_thay_cv = false, tim_thay_nv = false;
    
    for (int i = 0; i < so_luong_cong_viec; i++) {
        if (danh_sach_cong_viec[i].ma_so == ma_cong_viec) {
            danh_sach_cong_viec[i].nguoi_phu_trach = ma_nhan_vien;
            strcpy(danh_sach_cong_viec[i].trang_thai, "Chưa bắt đầu");
            tim_thay_cv = true;
            break;
        }
    }

    for (int i = 0; i < so_luong_nhan_vien; i++) {
        if (danh_sach_nhan_vien[i].ma_so == ma_nhan_vien) {
            tim_thay_nv = true;
            break;
        }
    }

    if (tim_thay_cv && tim_thay_nv) {
        printf("Đã phân công thành công!\n");
    } else {
        printf("Phân công thất bại! Kiểm tra lại mã số.\n");
    }
}
