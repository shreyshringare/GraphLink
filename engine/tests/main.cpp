#include <iostream>
#include <graphlink/union_find.hpp>

int main()
{
    graphlink::UnionFind uf(6);

    std::cout << std::boolalpha;

    std::cout << "Initial Components: "
              << uf.components() << "\n\n";

    std::cout << "3 connected to itself: "
              << uf.connected(3,3) << "\n\n";

    uf.unite(0,1);
    uf.unite(1,2);
    uf.unite(2,3);

    uf.unite(4,5);

    std::cout << "0 and 3 connected: "
              << uf.connected(0,3) << '\n';

    std::cout << "0 and 4 connected: "
              << uf.connected(0,4) << '\n';

    std::cout << "Components: "
              << uf.components() << '\n';

    uf.unite(0,3);

    std::cout << "Components after duplicate union: "
              << uf.components() << '\n';

    std::cout << "\nRoots\n";

    for(int i=0;i<6;i++)
    {
        std::cout
            << i
            << " -> "
            << uf.find(i)
            << '\n';
    }

    return 0;
}