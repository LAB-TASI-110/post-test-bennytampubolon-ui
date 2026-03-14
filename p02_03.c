#include <stdio.h>

int main() {
    const char *menu_names[] = {"Nasgor", "Kopi", "Goreng", "Seblak", "Susu"};
    const int menu_prices[] = {15000, 7000, 10000, 12000, 9000};
    int menu_quantities[] = {0, 0, 0, 0, 0};
    const int menu_count = 5;

    int num_orders = 0;
    int total_price = 0;

    printf("=== Program Kasir ===\n");
    for (int i = 0; i < menu_count; i++) {
        printf("%d. %-10s - Rp %d\n", i + 1, menu_names[i], menu_prices[i]);
    }
    printf("=====================\n\n");

    printf("Masukkan jumlah jenis pesanan berbeda yang ingin dibuat: ");
    if (scanf("%d", &num_orders) != 1 || num_orders <= 0) {
        printf("Input tidak valid. Program dihentikan.\n");
        return 1;
    }

    for (int i = 0; i < num_orders; i++) {
        int choice = 0;
        int qty = 0;

        printf("\nPesanan ke-%d\n", i + 1);
        printf("Masukkan nomor menu (1-%d): ", menu_count);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= menu_count) {
            printf("Masukkan jumlah porsi: ");
            scanf("%d", &qty);

            if (qty > 0) {
                menu_quantities[choice - 1] += qty;
            } else {
                printf("Jumlah porsi harus lebih dari 0. Pesanan diabaikan.\n");
            }
        } else {
            printf("Nomor menu tidak ditemukan. Pesanan diabaikan.\n");
        }
    }

    printf("\n=== Rincian Pesanan ===\n");
    printf("%-10s | %-10s | %-15s\n", "Jenis", "Jumlah", "Subtotal");
    printf("----------------------------------------\n");

    for (int i = 0; i < menu_count; i++) {
        if (menu_quantities[i] > 0) {
            int subtotal = menu_quantities[i] * menu_prices[i];
            printf("%-10s | %-10d | Rp %d\n", menu_names[i], menu_quantities[i], subtotal);
            total_price += subtotal;
        }
    }

    printf("----------------------------------------\n");
    printf("Total Harga Keseluruhan     : Rp %d\n", total_price);
    printf("========================================\n");

    return 0;
}