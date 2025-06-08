void tim_kiem_cong_viec() {
    int lua_chon;
    printf("\n--- TIM KIEM CONG VIEC ---\n");
    printf("1. Tim theo ma cong viec\n");
    printf("2. Tim theo ten cong viec\n");
    printf("3. Tim theo ten nhan vien phu trach\n");
    printf("Chon cach tim: ");
    scanf("%d", &lua_chon);
    getchar();

    if (lua_chon == 1) {
        int ma;
        printf("Nhap ma cong viec: ");
        scanf("%d", &ma);
        getchar();

        int found = 0;
        for (int i = 0; i < so_luong_cong_viec; i++) {
            if (danh_sach_cong_viec[i].ma_so == ma) {
                printf("- [%d] %s | Nhan vien: %s | Tien do: %d%% | Trang thai: %s\n",
                    danh_sach_cong_viec[i].ma_so,
                    danh_sach_cong_viec[i].mo_ta,
                    danh_sach_cong_viec[i].ten_nhan_vien,
                    danh_sach_cong_viec[i].tien_do,
                    danh_sach_cong_viec[i].trang_thai);
                found = 1;
                break;
            }
        }
        if (!found) printf("Khong tim thay cong viec!\n");

    } else if (lua_chon == 2) {
        char ten[100];
        printf("Nhap tu khoa ten cong viec: ");
        fgets(ten, sizeof(ten), stdin);
        ten[strcspn(ten, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < so_luong_cong_viec; i++) {
            if (strstr(danh_sach_cong_viec[i].mo_ta, ten)) {
                printf("- [%d] %s | Nhan vien: %s | Tien do: %d%% | Trang thai: %s\n",
                    danh_sach_cong_viec[i].ma_so,
                    danh_sach_cong_viec[i].mo_ta,
                    danh_sach_cong_viec[i].ten_nhan_vien,
                    danh_sach_cong_viec[i].tien_do,
                    danh_sach_cong_viec[i].trang_thai);
                found = 1;
            }
        }
        if (!found) printf("Khong tim thay cong viec phu hop!\n");

    } else if (lua_chon == 3) {
        char nhanvien[50];
        printf("Nhap ten nhan vien: ");
        fgets(nhanvien, sizeof(nhanvien), stdin);
        nhanvien[strcspn(nhanvien, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < so_luong_cong_viec; i++) {
            if (strcmp(danh_sach_cong_viec[i].ten_nhan_vien, nhanvien) == 0) {
                printf("- [%d] %s | Tien do: %d%% | Trang thai: %s\n",
                    danh_sach_cong_viec[i].ma_so,
                    danh_sach_cong_viec[i].mo_ta,
                    danh_sach_cong_viec[i].tien_do,
                    danh_sach_cong_viec[i].trang_thai);
                found = 1;
            }
        }
        if (!found) printf("Khong tim thay cong viec cua nhan vien do!\n");

    } else {
        printf("Lua chon khong hop le!\n");
    }
}
