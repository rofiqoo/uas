#include <iostream>
#include <vector>
#include <algorithm>

// Definisi struct anak
struct Anak {
    std::string nama, tanggal_lahir;
};

int main() {
    std::vector<Anak> data_anak;

    for (int i = 0; i < 20; ++i) {
        Anak anak;
        std::cout << "Nama anak: ";
        std::cin >> anak.nama;
        std::cout << "Tanggal lahir (format: DD MM YYYY): ";
        std::cin >> anak.tanggal_lahir;
        data_anak.push_back(anak);
    }

    std::cout << "\nData sebelum diurutkan:\n";
    for (const auto& anak : data_anak) {
        std::cout << "Nama: " << anak.nama << ", Tanggal Lahir: " << anak.tanggal_lahir << "\n";
    }

    std::sort(data_anak.begin(), data_anak.end(), [](const Anak& a, const Anak& b) {
        return a.tanggal_lahir.substr(6) < b.tanggal_lahir.substr(6);
    });

    std::cout << "\nData setelah diurutkan:\n";
    for (const auto& anak : data_anak) {
        std::cout << "Nama: " << anak.nama << ", Tanggal Lahir: " << anak.tanggal_lahir << "\n";
    }

    std::cout << "\nData anak dengan tahun lahir 2020:\n";
    for (const auto& anak : data_anak) {
        if (anak.tanggal_lahir.substr(6) == "2020") {
            std::cout << "Nama: " << anak.nama << ", Tanggal Lahir: " << anak.tanggal_lahir << "\n";
        }
    }

 return 0;
}