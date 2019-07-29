#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <utility>
#include <string.h>

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

#define MAX(a,b) ( ((a)>(b)) ? (a):(b) )
#define MIN(a,b) ( ((a)>(b)) ? (b):(a) )

int main(int, char**) {
    int account, item_num;
    scanf("%d %d", &account, &item_num);
    Item* items = (Item*)malloc(sizeof(Item) * (item_num + 1));
    for (int i = 1; i <= item_num; ++i) {
        Item* item = &items[i];
        scanf("%d %d %d", &item->price_, &item->importance_, &item->main_);
        item->prio_ = item->price_ * item->importance_;
    }
    int** ret_array = (int**)malloc((item_num + 1) * sizeof(int*));
    for (int i = 0; i <= item_num; ++i) {
        ret_array[i] = (int*)malloc((account + 1) * sizeof(int));
        memset(ret_array[i], 0, (account + 1) * sizeof(int));
    }

    for (int i = 1; i <= item_num; ++i) {
        for (int j = 1; j <= account; ++j) {
            if (items[i].main_ == 0) {
                if (items[i].price_ <= j)
                    ret_array[i][j] = MAX(ret_array[i - 1][j], (ret_array[i - 1][j - items[i].price_] + items[i].prio_));
            }
            else
                if ((items[i].price_ + items[items[i].main_].price_) <= j)
                    ret_array[i][j] = MAX(ret_array[i - 1][j], (ret_array[i - 1][j - items[i].price_] + items[i].prio_));
        }
    }
    printf("%d\n", ret_array[item_num][account]);
    for (int i = 0; i < item_num; ++i)
        free(ret_array[i]);
    free(ret_array);
    free(items);
    return 0;
}

/*
int main()
{
    int N, m, i, j, temp;
    int f[61][32001], v[61], q[61], vp[61];
    cin >> N >> m;
    for (i = 1; i <= m; i++){
        cin >> v[i] >> temp >> q[i];
        vp[i] = v[i] * temp;
    }
    for (i = 1; i <= m; i++)
        for (j = 1; j <= N; j++){
            if (q[i] == 0){
                if (v[i] <= j)
                    f[i][j] = max(f[i-1][j], (f[i-1][j - v[i]] + vp[i]));
            }
            else{
                if ((v[i] + v[q[i]]) <= j)
                    f[i][j] = max(f[i - 1][j], (f[i - 1][j - v[i]] + vp[i]));
            }
        }
    cout << f[m][N] << endl;
    return 0;
}
*/
