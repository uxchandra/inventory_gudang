#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char kodeMasuk[10][100];     //Array dua dimensi untuk menyimpan nomor seri barang
    char nama[100][100];    //Array dua dimensi untuk menyimpan nama barang
    int totalBarang[100];   //Array untuk menyimpan jumlah barang masuk
    char tanggalMasuk[20][100];     //Array dua dimensi untuk menyimpan tanggal masuk barang.
    int barangKeluar[100];          //Array untuk menyimpan jumlah barang yang keluar.
    char tanggalKeluar[20][100];    //Array dua dimensi untuk menyimpan tanggal keluar barang.
    int sisaBarang[100];            //Array untuk menyimpan sisa barang setelah barang keluar.
    int n = 0;                     /*untuk menghitung jumlah barang yang telah diinput, nilai n diinisialisasi dengan 0,
                            yang berarti saat program pertama kali dijalankan, belum ada data barang yang tersimpan*/
    int jumlahMasuk;        //variabel untuk input beberapa brg sekaligus
    int jumlahKeluar;       //variabel untuk mengeluarkan beberapa brg sekaligus
    char cekSatuan[10];     //variabel untuk cek brg per unit
    int pilihan;            //variabel untuk pilihan menu yg akan diinput pengguna

    printf("\t==============================================\n");
    printf("\t|                                            |\n");
    printf("\t|        Pengadaan Barang pada Gudang        |\n");
    printf("\t|                                            |\n");
    printf("\t==============================================\n");

    /*Penggunaan looping do while untuk menjalankan program, program akan terus melakukan
    perulangan sampai user memilih angka 5 untuk keluar dari program*/

    do {
        printf("\n\t Silakan pilih opsi menu \n");
        printf("\t 1. Input barang\n");
        printf("\t 2. Barang keluar\n");
        printf("\t 3. Cek stok barang satuan\n");
        printf("\t 4. Cek stok barang keseluruhan\n");
        printf("\t 5. Keluar\n\n");

        printf("\t Masukkan opsi nomor : ");
        scanf("%d", &pilihan);

        /*switch digunakan untuk mengatur menu pengelolaan barang pada gudang,
        Setiap case mengandung logika dan aksi yang sesuai dengan pilihan menu yang dipilih*/

        switch (pilihan) {
            case 1:
                printf("\t Masukkan jumlah barang yang akan diinput: ");
                scanf("%d", &jumlahMasuk);
                printf("\n\t======================================================\n");

                //perulangan ini digunakan untuk mengulang proses input data barang sebanyak 'jumlahMasuk' yang ditentukan oleh pengguna.
                //perulangan ini memungkinkan user untuk menginput beberapa barang sekaligus
                for (int i = 0; i < jumlahMasuk; i++) {
                    printf("\t Masukkan nomor seri barang: ");
                    scanf("%s", kodeMasuk[n]);

                    printf("\t Masukkan nama barang: ");
                    scanf(" %s", nama[n]);

                    printf("\t Masukkan total barang: ");
                    scanf("%d", &totalBarang[n]);

                    printf("\t Masukkan tanggal masuk (dd/mm/yyyy): ");
                    scanf("%s", tanggalMasuk[n]);

                    /*memastikan bahwa saat data barang baru diinputkan, nilai awal untuk jumlah barang yang keluar diatur menjadi 0,
                    dan sisa barang diatur sama dengan total barang yang diinputkan, sebelum adanya pengurangan jumlah barang yang keluar nantinya*/
                    barangKeluar[n] = 0;
                    sisaBarang[n] = totalBarang[n];

                    printf("\n\t======================================================\n");

                    n++;
                }

                break;
            case 2:
                printf("\t Masukkan jumlah barang yang akan dikeluarkan: ");
                scanf("%d", &jumlahKeluar);
                printf("\n\t======================================================\n");

                //perulangan ini digunakan untuk mengulang proses pengeluaran barang sebanyak 'jumlahKeluar' yang ditentukan oleh pengguna.
                //perulangan ini memungkinkan user untuk mengeluarkan beberapa barang sekaligus
                for (int i = 0; i < jumlahKeluar; i++) {
                    char kodeKeluar[10];
                    printf("\t Masukkan nomor seri barang: ");
                    scanf("%s", kodeKeluar);

                    //strcmp() digunakan untuk membandingkan dua string. Jika kedua string tersebut sama, kondisi akan terpenuhi.
                    //perulangan ini bertujuan untuk mencari nomor seri barang yang sesuai dengan kodeKeluar di dalam array kode
                    int j;
                    for (j = 0; j < n; j++) {
                        if (strcmp(kodeKeluar, kodeMasuk[j]) == 0) {
                            int jumlahBarangKeluar;
                            printf("\t Masukkan jumlah barang: ");
                            scanf("%d", &jumlahBarangKeluar);

                            if (jumlahBarangKeluar > sisaBarang[j]) {
                                printf("\t Maaf jumlah barang yang akan diambil melebihi stok barang yang ada\n");
                            } else {
                                barangKeluar[j] += jumlahBarangKeluar; // menambahkan jumlah barang yang keluar ke dalam variabel 'barangKeluar'
                                sisaBarang[j] -= jumlahBarangKeluar; // mengurangi jumlah barang yang keluar dari variabel 'sisaBarang'
                            }

                            printf("\t Masukkan tanggal keluar (dd/mm/yyyy): ");
                            scanf("%s", tanggalKeluar[j]);

                            printf("\t Barang berhasil dikeluarkan\n");

                            printf("\n\t======================================================\n");
                            break;
                        }
                    }

                    /*Jika kondisi j == n terpenuhi, artinya perulangan mencapai akhir tanpa menemukan nomor seri barang yang sesuai dengan kodeKeluar.
                    Ini berarti nomor seri barang yang dimasukkan tidak ditemukan dalam array kode*/
                    if (j == n) {
                        printf("\t Nomor seri barang tidak ditemukan\n");
                    }
                }
                break;


            case 3:
                printf("\t Masukkan nomor seri barang : ");
                scanf("%s", cekSatuan);
                int ketemu = 0; //sebagai penanda untuk menentukan apakah nomor seri barang yang dicari ditemukan atau tidak.

                //Perulangan untuk mencari no seri di variabel 'kodeMasuk'
                //Jika strcmp() mengembalikan nilai 0, itu berarti kedua string tersebut identik atau sama.
                for (int i = 0; i < n; i++) {
                    if (strcmp(cekSatuan, kodeMasuk[i]) == 0) {
                        printf("\t Stok barang untuk nomor seri %s (%s): %d\n", kodeMasuk[i], nama[i], sisaBarang[i]);
                        ketemu = 1;
                        break;
                    }
                }

                //jika no seri tidak ditemukan, maka aksinya sperti berikut
                if (!ketemu) {
                    printf("\t Nomor seri barang tidak ditemukan\n");
                }
                break;

            case 4:
                printf("\t Data barang saat ini:\n");
                printf("\t ----------------------------------------------------------------------------------------------------\n");
                printf("\t | %-10s | %-10s | %-12s | %-10s | %-14s | %-10s | %-12s |\n", "No. Seri", "Nama", "Barang Masuk", "Tanggal", "Barang Keluar", "Tanggal", "Sisa Barang");
                printf("\t ----------------------------------------------------------------------------------------------------\n");
                //perulangan ini akan membuat setiap data barang akan dicetak secara berurutan
                for (int i = 0; i < n; i++) {
                    printf("\t | %-10s | %-10s | %-12d | %-10s | %-14d | %-10s | %-12d |\n", kodeMasuk[i], nama[i], totalBarang[i], tanggalMasuk[i], barangKeluar[i], tanggalKeluar[i], sisaBarang[i]);
                }
                printf("\t ----------------------------------------------------------------------------------------------------\n");
                break;

            case 5:
                printf("\t Terima kasih telah menggunakan program ini\n");
                break;

            default:
                printf("\t Pilihan tidak valid\n");
        }

        /*getch digunakan untuk menahan program agar tidak langsung melakukan
        perulangan ketika aksi selesai*/

        getch();

    } while (pilihan != 5);

    return 0;
}



