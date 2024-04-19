
/* herder file and namespace for pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>order_set;
*/
// [erase element from pb_ds]
bool Exist(order_set &s, int x) { //this function checks weather the value (x) exists in the set or not.
     if ((s.upper_bound(x)) == s.end()) {
                    return 0;
                }
                return ((*s.upper_bound(x)) == x);
            }
void Erase(order_set &s, int x) { //this function erases one occurrence of the value (x).
                if (Exist(s, x)) {
                    s.erase(s.upper_bound(x));
                }
    
    }
// pb ds special operation
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
