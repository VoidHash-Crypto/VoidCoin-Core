# VoidCoin Core

VoidCoin Core is the reference implementation for the VoidCoin network: a proof-of-work blockchain with quantum-resistant ownership support, large-scale settlement capacity, and long-term monetary durability.

VoidCoin uses the **VOID** currency unit. The base unit is the Quark, where:

`1 VOID = 100,000,000 Quarks`

## Network Properties

- **Ticker:** VOID
- **Max Supply:** 231,000,000 VOID
- **Block Reward:** 50 VOID (halving every 2,100,000 blocks)
- **Block Target:** 60 seconds
- **Algorithm:** SHA256d (Proof of Work)
- **P2P Port:** 7777
- **RPC Port:** 7778

## Address Types

- `V...` — Native P2PKH addresses
- `3...` — P2SH addresses
- `vqr1...` — Native quantum-resistant P2QR addresses

## Building VoidCoin Core

Build instructions are available in the documentation directory:

* [Unix build notes](/doc/build-unix.md)
* [Windows build notes](/doc/build-windows.md)
* [macOS build notes](/doc/build-osx.md)

## Links

- GitHub: https://github.com/VoidHash-Crypto/VoidCoin-Core
- Organization: https://github.com/VoidHash-Crypto
