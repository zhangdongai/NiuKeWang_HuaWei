#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <utility>

typedef struct Item {
    short price_;
    char importance_;
    char main_; 
    int prio_;
} Item;

std::vector<Item> v_items;
std::vector<Item> tmp_v_items;

int get_total_prio(const Item* const items, const int item_num, const int begin, const int remained_account) {
    int total_prio = 0;
    for (int i = begin; i < item_num; ++i) {
        int tmp_total_prio = 0;
        if (items[i].main_ == 0) {
            int tmp_remained_account = remained_account - items[i].price_;
            if (tmp_remained_account < 0)
                continue;
            else {
                tmp_total_prio = items[i].prio_;
                tmp_total_prio += get_total_prio(items, item_num, i + 1, tmp_remained_account);
                if (tmp_total_prio > total_prio) {
//                    printf("find greater %d %d\n", total_prio, i);
                    total_prio = tmp_total_prio;
                }
            }
        }
        else {
            int tmp_remained_account = remained_account - items[i].price_ - items[items[i].main_ - 1].price_;
            if (tmp_remained_account < 0)
                continue;
            else {
                tmp_total_prio = (items[i].prio_ + items[items[i].main_ - 1].prio_);
                tmp_total_prio += get_total_prio(items, item_num, i + 1, tmp_remained_account);
                if (tmp_total_prio > total_prio) {
//                    printf("find greater %d %d\n", total_prio, i);
                    total_prio = tmp_total_prio;
//                    v_items = std::move(tmp_v_items);
                }
            }
        }
        if (tmp_total_prio > total_prio) {
            total_prio = tmp_total_prio;
//            v_items = std::move(tmp_v_items);
        }
    }
    return total_prio;
}

int main(int, char**) {
    int account, item_num;
    scanf("%d %d", &account, &item_num);
    Item* items = (Item*)malloc(sizeof(Item) * item_num);
    for (int i = 0; i < item_num; ++i) {
        Item* item = &items[i];
        scanf("%d %d %d", &item->price_, &item->importance_, &item->main_);
        item->prio_ = item->price_ * item->importance_;
    }

    int total_prio = get_total_prio(items, item_num, 0, account);
    printf("%d\n", total_prio);
//    for (const auto& e : v_items)
//        printf("%d %d %d\n", e.price_, e.importance_, e.main_);
    free(items);
    return 0;
}
