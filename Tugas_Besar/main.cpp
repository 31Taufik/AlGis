#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <conio.h>

using namespace std;
void penukaranKoin() {
    cout << "--- Algoritma Penukaran Koin ---" << endl;
    int n_koin;
    cout << "Masukkan jumlah jenis koin: ";
    cin >> n_koin;
    vector<int> koin(n_koin);
    cout << "Masukkan " << n_koin << " jenis koin (misal: 1000 500 200 100): ";
    for (int i = 0; i < n_koin; ++i) cin >> koin[i];
    sort(koin.rbegin(), koin.rend());
    int jumlahUang;
    cout << "Masukkan jumlah uang yang akan ditukar: ";
    cin >> jumlahUang;
    cout << endl;
    cout << "Koin yang dibutuhkan:" << endl;
    int sisaUang = jumlahUang;
    for (int k : koin) {
        if (sisaUang >= k) {
            int jumlahKoin = sisaUang / k;
            cout << jumlahKoin << " keping koin " << k << endl;
            sisaUang %= k;
        }
    }
    if (sisaUang > 0) cout << "Sisa uang tidak dapat ditukar: " << sisaUang << endl;
    cout << "----------------------------------------------" << endl;
}

struct Item {
    int id;
    int weight;
    int profit;
    double ratio;
};
bool compareItems(Item a, Item b) { return a.ratio > b.ratio; }

void knapsackProblem() {
    cout << "\n--- Algoritma Knapsack Problem ---" << endl;
    string nim;
    cout << "Masukkan 8 digit NIM Anda: ";
    cin >> nim;
    if (nim.length() != 8) {
        cout << "NIM harus terdiri dari 8 digit. Silakan coba lagi." << endl;
        return;
    }
    vector<Item> items(8);
    vector<int> profits = {21, 35, 70, 42, 80, 20, 10, 5};
    int kapasitasMaksimal = 15;
    cout << "\nData Objek Berdasarkan NIM " << nim << ":" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Objek\tWeight\tProfit\tRatio (P/W)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < 8; ++i) {
        items[i].id = i + 1;
        int digit = nim[i] - '0';
        items[i].weight = (digit == 0) ? 11 : digit;
        items[i].profit = profits[i];
        items[i].ratio = (items[i].weight > 0) ? (double)items[i].profit / items[i].weight : 0;
        cout << items[i].id << "\t" << items[i].weight << "\t" << items[i].profit << "\t" << fixed << setprecision(2) << items[i].ratio << endl;
    }
    cout << "----------------------------------------------------" << endl;
    sort(items.begin(), items.end(), compareItems);
    double totalProfit = 0;
    int sisaKapasitas = kapasitasMaksimal;
    cout << "\nProses Pengisian Knapsack (Kapasitas = " << kapasitasMaksimal << "):" << endl;
    for (const auto& item : items) {
        if (sisaKapasitas <= 0) break;
        if (item.weight <= sisaKapasitas) {
            sisaKapasitas -= item.weight;
            totalProfit += item.profit;
            cout << "-> Mengambil seluruh Objek " << item.id << " (weight: " << item.weight << ", profit: " << item.profit << ")" << endl;
        } else {
            double fraksi = (double)sisaKapasitas / item.weight;
            totalProfit += item.profit * fraksi;
            cout << "-> Mengambil " << fixed << setprecision(2) << fraksi * 100 << "% dari Objek " << item.id << " (weight: " << sisaKapasitas << ", profit: " << item.profit * fraksi << ")" << endl;
            sisaKapasitas = 0;
        }
    }
    cout << "\n----------------------------------------------" << endl;
    cout << "Total Profit Maksimal: " << fixed << setprecision(2) << totalProfit << endl;
    cout << "----------------------------------------------" << endl;
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSortHandler() {
    cout << "\n--- Algoritma Merge Sort ---" << endl;
    int n;
    cout << "Masukkan jumlah elemen yang akan diurutkan: ";
    cin >> n;
    vector<int> data(n);
    cout << "Masukkan " << n << " angka (dipisah spasi): ";
    for (int i = 0; i < n; ++i) cin >> data[i];
    cout << "\nData sebelum diurutkan: ";
    for (int val : data) cout << val << " ";
    cout << endl;
    mergeSort(data, 0, n - 1);
    cout << "Data setelah diurutkan: ";
    for (int val : data) cout << val << " ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
}

int main() {
    int pilihan;
    bool firstRun = true;

    do {
        system("cls || clear");
        cout << "Created By:";
        cout << "\nMuhammad Taufik Hidayat";
        cout << "\n23533739";
        cout << "\nTI 4B\n";
        cout << endl;

        cout << "===== MENU TUGAS BESAR PRAK-SAS =====" << endl;
        cout << "1. Penukaran Koin" << endl;
        cout << "2. Knapsack Problem" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "0. Keluar" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        system("cls || clear");

        if (cin.fail()) {
            cout << "Input tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = -1;
        } else {
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan) {
            case 1:
                penukaranKoin();
                break;
            case 2:
                knapsackProblem();
                break;
            case 3:
                mergeSortHandler();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                cout << "\nCreated By:";
                cout << "\nMuhammad Taufik Hidayat";
                cout << "\n23533739";
                cout << "\nTI 4B\n";
                break;
            default:
                if (pilihan != -1) {
                   cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                }
                break;
        }

        if (pilihan != 0) {
            cout << "\nCreated By:";
            cout << "\nMuhammad Taufik Hidayat";
            cout << "\n23533739";
            cout << "\nTI 4B\n";
            cout << "\nTekan [SPASI] untuk kembali ke menu...";
            while (true) {
                char tombol = getch();
                if (tombol == ' ') {
                    break;
                }
            }
        }

    } while (pilihan != 0);

    return 0;
}
