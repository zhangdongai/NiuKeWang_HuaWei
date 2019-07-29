#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int key_;
    int value_;
} Node;

void insert_sort(Node* const nodes, const int array_num) {
    for (int i = 1; i <= array_num - 1; ++i) {
        int tmp_key = nodes[i].key_;
        int tmp_value = nodes[i].value_;
        int j = i;
        for (; j >0 && nodes[j - 1].key_ > tmp_key; --j) {
            nodes[j].key_ = nodes[j - 1].key_;
            nodes[j].value_ = nodes[j - 1].value_;
        }
        nodes[j].key_ = tmp_key;
        nodes[j].value_ = tmp_value;
    }
}

int main(int argc, char** argv) {
    int array_num = 0;
    scanf("%d", &array_num);
    Node* nodes = (Node*)malloc(sizeof(Node) * array_num);
    for (int i = 0; i < array_num; ++i) {
        nodes[i].key_ = -1;
        nodes[i].value_ = 0;
    }
    int key, value;
    int exist_index = 0;
    int next_index = 0;
    int input_num = 0;
    while (input_num++ < array_num) {
        scanf("%d %d", &key, &value);
        bool find = false;
        for (int i = 0; i < array_num; ++i) {
            if (nodes[i].key_ == key) {
                nodes[i].value_ += value;
                find = true;
                break;
            }
        }
        if (!find) {
            nodes[next_index].key_ = key;
            nodes[next_index++].value_ += value;
        }
    }
//    insert_sort(nodes, array_num);
    for (int i = 0; i < array_num; ++i) {
        if (nodes[i].key_ != -1)
            printf("%d %d\n", nodes[i].key_, nodes[i].value_);
    }
    return 0;
}
