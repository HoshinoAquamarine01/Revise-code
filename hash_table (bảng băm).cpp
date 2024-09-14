#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>  // Sử dụng cho gp_hash_table
using namespace __gnu_pbds;
using namespace std;

// Khai báo gp_hash_table: bảng băm hiệu suất cao
typedef gp_hash_table<int, string> hash_table;

int main() {
    // Tạo bảng băm
    hash_table my_table;

    // Chèn phần tử vào bảng băm (key-value)
    my_table[1] = "One";
    my_table[2] = "Two";
    my_table[3] = "Three";
    my_table[4] = "Four";

    // Duyệt qua các phần tử trong bảng băm và xuất ra
    cout << "Các phần tử trong bảng băm:" << endl;
    for (auto& it : my_table) {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    // Kiểm tra sự tồn tại của một key
    int key_to_find = 3;
    if (my_table.find(key_to_find) != my_table.end()) {
        cout << "Tìm thấy key " << key_to_find << " với giá trị: " << my_table[key_to_find] << endl;
    } else {
        cout << "Không tìm thấy key " << key_to_find << endl;
    }

    // Xóa một phần tử
    int key_to_erase = 2;
    my_table.erase(key_to_erase);
    cout << "Đã xóa key " << key_to_erase << endl;

    // Kiểm tra kích thước của bảng băm
    cout << "Kích thước bảng băm: " << my_table.size() << endl;

    // Kiểm tra bảng băm có rỗng hay không
    if (my_table.empty()) {
        cout << "Bảng băm rỗng" << endl;
    } else {
        cout << "Bảng băm không rỗng" << endl;
    }

    // Truy cập trực tiếp vào một key
    cout << "Giá trị của key 1: " << my_table[1] << endl;

    // Làm trống bảng băm
    my_table.clear();
    cout << "Đã làm trống bảng băm. Kích thước hiện tại: " << my_table.size() << endl;

    return 0;
}
