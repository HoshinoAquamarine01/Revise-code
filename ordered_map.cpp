#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Khai báo ordered_map sử dụng tree trong pb_ds
typedef tree<
    int,               // Key type
    string,            // Mapped (value) type
    less<int>,         // So sánh nhỏ hơn
    rb_tree_tag,       // Kiểu cây (Red-Black tree)
    tree_order_statistics_node_update> ordered_map;

int main() {
    // Tạo ordered_map
    ordered_map o_map;

    // Chèn các phần tử vào ordered_map (key-value)
    o_map[5] = "Five";
    o_map[3] = "Three";
    o_map[8] = "Eight";
    o_map[1] = "One";
    o_map[6] = "Six";

    // Duyệt qua các phần tử trong ordered_map và xuất ra
    cout << "Các phần tử trong ordered_map:" << endl;
    for (auto& it : o_map) {
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    // Tìm phần tử theo thứ tự (find_by_order)
    int idx = 2;  // Thứ tự bắt đầu từ 0
    if (idx < o_map.size()) {
        auto it = o_map.find_by_order(idx);
        cout << "Phần tử thứ " << idx << ": Key = " << it->first << ", Value = " << it->second << endl;
    } else {
        cout << "Không tìm thấy phần tử có thứ tự " << idx << endl;
    }

    // Tìm thứ tự của phần tử có key (order_of_key)
    int key_to_find = 6;
    cout << "Thứ tự của key " << key_to_find << " trong ordered_map: " << o_map.order_of_key(key_to_find) << endl;

    // Xóa một phần tử theo key
    int key_to_erase = 3;
    o_map.erase(key_to_erase);
    cout << "Đã xóa key " << key_to_erase << endl;

    // Kiểm tra kích thước của ordered_map
    cout << "Kích thước ordered_map: " << o_map.size() << endl;

    // Kiểm tra ordered_map có rỗng không
    if (o_map.empty()) {
        cout << "ordered_map rỗng" << endl;
    } else {
        cout << "ordered_map không rỗng" << endl;
    }

    // Truy cập trực tiếp vào một key
    cout << "Giá trị của key 5: " << o_map[5] << endl;

    // Làm trống ordered_map
    o_map.clear();
    cout << "Đã làm trống ordered_map. Kích thước hiện tại: " << o_map.size() << endl;

    return 0;
}
