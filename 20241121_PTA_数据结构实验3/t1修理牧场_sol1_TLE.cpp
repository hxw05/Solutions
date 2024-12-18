#include "iostream"

using namespace std;

int main() {
    int n;
    int a[9999];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int s = 0;

    // 第n次循环中，数组为 00000000X 其中X是哈夫曼树的顶端权值，这种情况需要去掉，所以i<n-1
    for (int i = 0; i < n - 1; i++) {
        int minIndex;
        // 必须：minIndex指向的数组元素不能是空位（0）
        for (int k = 0; a[minIndex = k] == 0; k++);
        for (int j = 0; j < n; j++) {
            if (a[j] == 0) continue;
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int subminIndex;
        // 必须：满足不能是空位的同时，subminIndex和minIndex不能指向同一个元素。
        for (int k = 0; a[subminIndex = k] == 0 || k == minIndex; k++);
        for (int j = 0; j < n; j++) {
            if (a[j] == 0) continue;
            if (a[j] < a[subminIndex])
                if ((a[j] == a[minIndex] && j != minIndex) || a[j] > a[minIndex]) {
                    subminIndex = j;
                }
        }

//        for (int j = 0; j < n; j++) {
//            cout << a[j] << " ";
//        }
//
//        cout << endl;

        // 将两个小值中其中一个的位置用来存储和值，另一个置0弃用。
        a[minIndex] = a[minIndex] + a[subminIndex];
        s += a[minIndex];
        a[subminIndex] = 0;
    }

    cout << s << endl;
}