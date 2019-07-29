#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <utility>

typedef struct Item {
    short price_;
    char importance_;
    char main_; 
} Item;

std::vector<Item> v_items;
std::vector<Item> tmp_v_items;

bool price_match(const Item* const items, const int item_index, int* remained_account, bool catch_main) {
    if (items[item_index].main_ == 0) {
        int total_price = items[item_index].price_;
        if (total_price <= *remained_account) {
            *remained_account -= total_price;
            return true;
        }
    }
    else {
        int total_price = 0;
        if (catch_main)
            total_price = items[item_index].price_ + items[items[item_index].main_ - 1].price_;
        else
            total_price = items[item_index].price_;
        if(total_price <= *remained_account) {
            *remained_account -= total_price;
            return true;
        }
    }
    return false;
}

int get_total_prio(const Item* const items, const int item_num, const int item_index, int remained_account) {
    int total_prio = 0;
    for (int j = item_index + 1; j < item_num; ++j) {
//        if (items[item_index].main_ != 0 && items[item_index].main_ == j)
//            continue;
        bool catch_main = false;
        if (j < items[j].main_)
            catch_main = true;
        if (price_match(items, j, &remained_account, catch_main)) {
            total_prio += (items[j].price_ * items[j].importance_);
            tmp_v_items.push_back(items[j]);
        }
        else
            continue;
//        if (remained_account <= 0)
//            break;
    }
    return total_prio;
}

int get_total_prio(const Item* const items, const int begin, const int remained_account) {
    int total_prio = 0;
    for (int i = 0; i < item_num; ++i) {
        int tmp_total_prio = 0;
        if (items[i].main_ == 0) {
            int tmp_remained_account = remained_account - items[i].price_;
            if (tmp_remained_account < 0)
                continue;
            else {
                tmp_total_prio = (items[i].price_ * items[i].importance_);
                tmp_total_prio += get_total_prio(items, i + 1; tmp_remained_account);
                if (tmp_total_prio > total_prio) {
                    printf("find greater %d %d %d\n", total_prio, i, j);
                    total_prio = tmp_total_prio;
                }
            }
        }
        else {
            int remained_account = account - items[i].price_ - items[items[i].main_ - 1].price_;
            if (remained_account < 0)
                continue;
            else {
                tmp_total_prio = (items[i].price_ * items[i].importance_ + items[items[i].main_ - 1].price_ * items[items[i].main_ - 1].importance_);
                tmp_total_prio += get_total_prio(items, i + 1; tmp_remained_account);
                if (tmp_total_prio > total_prio) {
                    printf("find greater %d %d %d\n", total_prio, i, j);
                    total_prio = tmp_total_prio;
                }
                if (tmp_total_prio > total_prio) {
                    printf("find greater %d %d %d\n", total_prio, i, j);
                    total_prio = tmp_total_prio;
                    v_items = std::move(tmp_v_items);
                }
            }
        }
        if (tmp_total_prio > total_prio) {
            total_prio = tmp_total_prio;
            v_items = std::move(tmp_v_items);
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
    }

    int total_prio = get_total_prio(items, 0, account);
    printf("%d\n", total_prio);
    for (const auto& e : v_items)
        printf("%d %d %d\n", e.price_, e.importance_, e.main_);
    free(items);
    return 0;
}
