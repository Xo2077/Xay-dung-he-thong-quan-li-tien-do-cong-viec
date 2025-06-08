void cap_nhat_tien_do() {
    int ma_cong_viec, tien_do_moi;
    
    printf("\n--- CẬP NHẬT TIẾN ĐỘ ---\n");
    printf("Nhập mã công việc: ");
    scanf("%d", &ma_cong_viec);
    
    int vi_tri = -1;
    for (int i = 0; i < so_luong_cong_viec; i++) {
        if (danh_sach_cong_viec[i].ma_so == ma_cong_viec) {
            vi_tri = i;
            break;
        }
    }
    
    if (vi_tri == -1) {
        printf("Không tìm thấy công việc!\n");
        return;
    }
    
    printf("Công việc: %s\n", danh_sach_cong_viec[vi_tri].mo_ta);
    printf("Tiến độ hiện tại: %d%%\n", danh_sach_cong_viec[vi_tri].tien_do);
    
    printf("Nhập tiến độ mới (0-100): ");
    scanf("%d", &tien_do_moi);
    
    if (tien_do_moi < 0 || tien_do_moi > 100) {
        printf("Tiến độ không hợp lệ!\n");
        return;
    }
    
    danh_sach_cong_viec[vi_tri].tien_do = tien_do_moi;
    
    if (tien_do_moi == 0) {
        strcpy(danh_sach_cong_viec[vi_tri].trang_thai, "Chưa bắt đầu");
    } else if (tien_do_moi < 100) {
        strcpy(danh_sach_cong_viec[vi_tri].trang_thai, "Đang làm");
    } else {
        strcpy(danh_sach_cong_viec[vi_tri].trang_thai, "Hoàn thành");
    }
    
    printf("Đã cập nhật tiến độ!\n");
}