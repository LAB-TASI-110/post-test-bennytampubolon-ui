#include <stdio.h>
#include <string.h>

int main() {
    char kode_kota[4];
    float berat_butet;

    while (1) {
        // Membaca input kode kota
        if (scanf("%3s", kode_kota) != 1) break;
        
        // Cek kondisi berhenti
        if (strcmp(kode_kota, "END") == 0) {
            break;
        }

        // Membaca input berat paket Butet
        if (scanf("%f", &berat_butet) != 1) break;

        // Perhitungan berat berdasarkan gambar 3
        float berat_ucok = 1.5f * berat_butet;
        float total_berat = berat_butet + berat_ucok;

        // Inisialisasi variabel untuk tarif dan informasi kota (berdasarkan gambar 1 & 4)
        char nama_kota[20] = "";
        int harga_per_kg = 0;
        int is_luar_pulau = 0;
        int is_valid = 1;

        if (strcmp(kode_kota, "MDN") == 0) {
            strcpy(nama_kota, "Medan");
            harga_per_kg = 8000;
            is_luar_pulau = 0;
        } else if (strcmp(kode_kota, "BLG") == 0) {
            strcpy(nama_kota, "Balige");
            harga_per_kg = 5000;
            is_luar_pulau = 0;
        } else if (strcmp(kode_kota, "JKT") == 0) {
            strcpy(nama_kota, "Jakarta");
            harga_per_kg = 12000;
            is_luar_pulau = 1;
        } else if (strcmp(kode_kota, "SBY") == 0) {
            strcpy(nama_kota, "Surabaya");
            harga_per_kg = 13000;
            is_luar_pulau = 1;
        } else {
            is_valid = 0;
        }

        if (!is_valid) {
            printf("Kode kota %s tidak dikenali.\n\n", kode_kota);
            continue;
        }

        // Perhitungan ongkos kirim dasar
        float ongkos_dasar = total_berat * harga_per_kg;
        float total_ongkir = ongkos_dasar;
        char info_promo[100] = "Tidak ada promo";

        // Pengecekan syarat promo (berdasarkan gambar 2)
        // Syarat: Total berat > 10 kg DAN Pengiriman ke luar pulau
        if (total_berat > 10.0f && is_luar_pulau == 1) {
            float diskon = ongkos_dasar * 0.10f;
            total_ongkir = ongkos_dasar - diskon;
            strcpy(info_promo, "Diskon ongkir 10% & Asuransi gratis");
        }

        // Menampilkan Struk Pembayaran
        printf("========================================\n");
        printf("            STRUK PEMBAYARAN            \n");
        printf("========================================\n");
        printf("Kota Tujuan       : %s\n", nama_kota);
        printf("Berat Paket Butet : %.2f kg\n", berat_butet);
        printf("Berat Paket Ucok  : %.2f kg\n", berat_ucok);
        printf("Total Berat       : %.2f kg\n", total_berat);
        printf("Total Ongkos Kirim: Rp %.2f\n", total_ongkir);
        printf("Info Promo        : %s\n", info_promo);
        printf("========================================\n\n");
    }

    return 0;
}