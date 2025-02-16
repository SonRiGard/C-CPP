#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// Hàm ghi trạng thái các stack vào file
void logStack(ofstream &outFile, stack<int> A, stack<int> B, stack<int> C) {
    outFile << "A: ";
    stack<int> temp;
    while (!A.empty()) {
        temp.push(A.top());
        A.pop();
    }
    while (!temp.empty()) {
        outFile << temp.top() << " ";
        A.push(temp.top());
        temp.pop();
    }
    outFile << "\nB: ";
    while (!B.empty()) {
        temp.push(B.top());
        B.pop();
    }
    while (!temp.empty()) {
        outFile << temp.top() << " ";
        B.push(temp.top());
        temp.pop();
    }
    outFile << "\nC: ";
    while (!C.empty()) {
        temp.push(C.top());
        C.pop();
    }
    while (!temp.empty()) {
        outFile << temp.top() << " ";
        C.push(temp.top());
        temp.pop();
    }
    outFile << "\n----------------------\n";
}

// Hàm di chuyển đĩa trong thuật toán Tháp Hà Nội
void hanoi(int n, stack<int> &from, stack<int> &aux, stack<int> &to, ofstream &outFile) {
    if (n == 1) {
        to.push(from.top());
        from.pop();
        logStack(outFile, from, aux, to);
        return;
    }
    
    hanoi(n - 1, from, to, aux, outFile); // Di chuyển N-1 đĩa sang cọc phụ
    to.push(from.top()); // Di chuyển đĩa lớn nhất
    from.pop();
    logStack(outFile, from, aux, to); // Ghi trạng thái stack vào file
    hanoi(n - 1, aux, from, to, outFile); // Di chuyển N-1 đĩa từ cọc phụ sang cọc đích
}

int main() {
    stack<int> A, B, C;
    
    // Khởi tạo stack A với giá trị 4,3,2,1 (đĩa lớn ở dưới)
    for (int i = 4; i >= 1; --i) {
        A.push(i);
    }

    ofstream outFile("hanoi_stack_output.txt"); // Mở file để ghi kết quả
    if (!outFile) {
        cerr << "Không thể mở file để ghi!" << endl;
        return 1;
    }

    logStack(outFile, A, B, C); // Ghi trạng thái ban đầu
    hanoi(4, A, B, C, outFile); // Gọi thuật toán
    
    outFile.close(); // Đóng file sau khi ghi xong
    cout << "Quá trình di chuyển đã được lưu vào 'hanoi_stack_output.txt'" << endl;

    return 0;
}
