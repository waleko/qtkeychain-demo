#include <iostream>

#include <keychain.h>

int main() {
    QKeychain::WritePasswordJob j("qtkeychain-test");
    j.start();
    
    std::cout << "OK!" << std::endl;

    return 0;
}
