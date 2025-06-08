void xem_bao_cao_tien_do() {
    printf("\n BAO CAO TIEN DO CONG VIEC \n");
    printf("\n1. Danh sach cong viec: CHUA BAT DAU\n");
    for (int i = 0; i < so_luong_cong_viec; i++) {
        if (strcmp(danh_sach_cong_viec[i].trang_thai, "Chua bat dau") == 0) {
            printf("- [%d] %s (Nhan vien: %s, %d%%)\n",
                danh_sach_cong_viec[i].ma_so,
                danh_sach_cong_viec[i].mo_ta,
                danh_sach_cong_viec[i].ten_nhan_vien,
                danh_sach_cong_viec[i].tien_do);
        }
    }

    printf("\n2. Danh sach cong viec: DANG LAM\n");
    for (int i = 0; i < so_luong_cong_viec; i++) {
        if (strcmp(danh_sach_cong_viec[i].trang_thai, "Dang lam") == 0) {
            printf("- [%d] %s (Nhan vien: %s, %d%%)\n",
                danh_sach_cong_viec[i].ma_so,
                danh_sach_cong_viec[i].mo_ta,
                danh_sach_cong_viec[i].ten_nhan_vien,
                danh_sach_cong_viec[i].tien_do);
        }
    }

    printf("\n3. Danh sach cong viec: HOAN THANH\n");
    for (int i = 0; i < so_luong_cong_viec; i++) {
        if (strcmp(danh_sach_cong_viec[i].trang_thai, "Hoan thanh") == 0) {
            printf("- [%d] %s (Nhan vien: %s, %d%%)\n",
                danh_sach_cong_viec[i].ma_so,
                danh_sach_cong_viec[i].mo_ta,
                danh_sach_cong_viec[i].ten_nhan_vien,
                danh_sach_cong_viec[i].tien_do);
        }
    }

    printf("\n4. Tien do tung nhan vien:\n");
    for (int i = 0; i < so_luong_cong_viec; i++) {
        printf("- %s: %s (%d%%)\n",
            danh_sach_cong_viec[i].ten_nhan_vien,
            danh_sach_cong_viec[i].mo_ta,
            danh_sach_cong_viec[i].tien_do);
    }
}