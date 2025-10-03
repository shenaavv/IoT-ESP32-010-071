# Laporan IoT-ESP32-010-071

| Nama | NRP       |
|-------|-----------|
| Kanafira Vanesha P. | 5027241010   |
| Fika Arka N. | 5027241071  |
---

##  Overview Project

Program ini melakukan hal berikut:

- **Mengukur Jarak** menggunakan sensor ultrasonik (misalnya HC-SR04) untuk mendeteksi jarak objek.
- **Memberi Peringatan** dengan menyalakan LED jika objek berada pada jarak ≤ 10 cm.
- **Mengirim Data** hasil pengukuran ke platform IoT **ThingSpeak** melalui koneksi Wi-Fi setiap 20 detik.
<img width="814" height="546" alt="image" src="https://github.com/user-attachments/assets/5ca86d33-e49f-406f-a9b1-452f6326dbfa" />

---

## 1. Membuat Channel Baru

Pada halaman **My Channels**, klik tombol **"New Channel"** untuk memulai konfigurasi stream data baru.

<img width="450" alt="image" src="https://github.com/user-attachments/assets/12d7cefc-55eb-4b51-92fc-26e2cf7fd7e7" />

---

## 2. Pengaturan Channel

Isi konfigurasi sebagai berikut:

- **Nama Channel**: `Tugas 2 IOT 085 & 097`
- **Field 1**:
  - Label: `Distance`
  - Status: Diaktifkan

Pengaktifan Field 1 memastikan bahwa channel siap menerima data jarak pada kolom tersebut.
Lalu tekan save pada bagian bawah halaman.

<img width="954" height="799" alt="image" src="https://github.com/user-attachments/assets/37d71a04-8f0f-489d-8adf-4d712457c98f" />

---

## 3. Mengambil Write API Key

Buka tab **API Keys** untuk mendapatkan **Write API Key**.  
Contoh kunci: `OCQE8TM2NRXIFD8W`

Write API Key ini digunakan di dalam program untuk autentikasi saat pengiriman data.

<img width="1820" height="652" alt="image" src="https://github.com/user-attachments/assets/7e3e9d96-141a-45a3-aee6-0c8fb9d98a4f" />

---

## 4. Status Channel dan Data Masuk

Setelah perangkat mengirimkan data:

Successly Upload

<img width="1911" height="831" alt="image" src="https://github.com/user-attachments/assets/990b3192-6477-4bc3-a4f3-00f076662f0e" />

---

## 5. Kesimpulan

Konfigurasi channel, penggunaan API Key, dan pengiriman data dari perangkat telah berjalan dengan baik. Data berhasil direkam, dan grafik pada Field 1 memverifikasi bahwa sistem berfungsi namun data tidak bisa masuk ke thingspeak.
