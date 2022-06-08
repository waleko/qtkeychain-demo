#include <keychain.h>

int main() {
    QKeychain::WritePasswordJob j("qtkeychain-test");
    j.start();

    return 0;
}
