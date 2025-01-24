// Problem: Tree manipulation & Traversal
// Description
// Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
// Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
// · MakeRoot u: Tạo ra nút gốc u của cây
// · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
// · PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
// · InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
// · PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
// Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
// Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
// Ví dụ
// Dữ liệu
// MakeRoot 10
// Insert 11 10
// Insert 1 10
// Insert 3 10
// InOrder
// Insert 5 11
// Insert 4 11
// Insert 8 3
// PreOrder
// Insert 2 3
// Insert 7 3
// Insert 6 4
// Insert 9 4
// InOrder
// PostOrder
// *
// Kết quả
// 11 10 1 3
// 10 11 5 4 1 3 8
// 5 11 6 4 9 10 1 8 3 2 7
// 5 6 9 4 11 1 8 2 7 3 10

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> child;
    Node(int data) : val(data) {}
};

void insert(Node *root, int parent, Node *node)
{
    if (!root)
    {
        root = node;
    }
    else
    {
        int len = root->child.size();
        for (int i = 0; i < len; i++)
        {
            if (root->child[i]->val == parent)
            {
                root->child[i]->child.push_back(node);
                return;
            }
            else
            {
                insert(root->child[i], parent, node);
            }
        }
    }
}

void levelorder(vector<Node *> &prev_level)
{
    vector<Node*> curr_level;
    for (int i = 0; i < prev_level.size(); i++)
    {
        cout << prev_level[i]->val << " ";
        for (int j = 0; j < prev_level[i]->child.size(); j++)
        {
            curr_level.push_back(prev_level[i]->child[j]);
        }
    }
    if (curr_level.size() == 0)
    {
        return;
    }
    else
    {
        levelorder(curr_level);
    }
}
