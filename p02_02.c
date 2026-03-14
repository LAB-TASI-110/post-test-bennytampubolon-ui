#include <stdio.h>
#include <stdlib.h>

/**
 * Berdasarkan pola pada gambar:
 * Item ke-1, 3, 5... (indeks 0, 2, 4...) adalah kategori 1 (Perlengkapan Sekolah: Dasi, Rok)
 * Item ke-2, 4, 6... (indeks 1, 3, 5...) adalah kategori 2 (Sembako: Gula, Minyak)
 */
int calculate_stock_by_category(int *stocks, int total_items, int target_category) {
    int total_stock = 0;
    for (int i = 0; i < total_items; i++) {
        int current_category = (i % 2 == 0) ? 1 : 2;
        
        if (current_category == target_category) {
            total_stock += stocks[i];
        }
    }
    return total_stock;
}

int main() {
    int total_data;

    // Input jumlah total data
    if (scanf("%d", &total_data) != 1 || total_data <= 0) {
        printf("Input tidak valid.\n");
        return 1;
    }

    // Alokasi memori dinamis untuk array stok
    int *stocks = (int *)malloc(total_data * sizeof(int));
    if (stocks == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    // Input deret stok
    for (int i = 0; i < total_data; i++) {
        if (scanf("%d", &stocks[i]) != 1) {
            printf("Input stok tidak valid.\n");
            free(stocks);
            return 1;
        }
    }

    // Input kode kategori barang (1 atau 2)
    int target_category;
    if (scanf("%d", &target_category) != 1 || (target_category != 1 && target_category != 2)) {
        printf("Kategori tidak valid. Pilih 1 atau 2.\n");
        free(stocks);
        return 1;
    }

    // Hitung dan tampilkan total stok sesuai kategori
    int total_stock = calculate_stock_by_category(stocks, total_data, target_category);
    printf("Total stok untuk kategori %d: %d\n", target_category, total_stock);

    // Bebaskan memori
    free(stocks);
    return 0;
}