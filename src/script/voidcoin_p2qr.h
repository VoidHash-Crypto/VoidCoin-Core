#ifndef VOIDCOIN_SCRIPT_VOIDCOIN_P2QR_H
#define VOIDCOIN_SCRIPT_VOIDCOIN_P2QR_H

#include <script/script.h>
#include <uint256.h>
#include <script/solver.h>
#include <crypto/pq/mldsa87/mldsa87.h>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

static constexpr size_t VOIDCOIN_P2QR_PUBKEY_SIZE = MLDSA87_PUBLIC_KEY_SIZE;
static constexpr size_t VOIDCOIN_P2QR_SIGNATURE_SIZE = MLDSA87_SIGNATURE_SIZE;

static constexpr unsigned int VOIDCOIN_P2QR_MULTISIG_MAX_KEYS = 1024;
static constexpr unsigned int VOIDCOIN_P2QR_MULTISIG_MAX_SIGNATURES = 1024;

struct VoidCoinP2QRMultisigSpend
{
    uint16_t required{0};
    uint16_t total{0};

    std::vector<std::vector<unsigned char>> signatures;
    std::vector<uint16_t> signer_indexes;

    // Legacy/live-chain pubkey-policy format:
    // <sig[m]> <signer_index[m]> <pubkey[n]> <m> <n>
    std::vector<std::vector<unsigned char>> pubkeys;

    // New signer-address/program-policy format:
    // <sig[m]> <signer_index[m]> <signing_pubkey[m]> <signer_program[n]> <m> <n>
    std::vector<std::vector<unsigned char>> signing_pubkeys;
    std::vector<uint256> signer_programs;
};

bool VoidCoinIsP2QRScriptPubKey(const CScript& script_pub_key, uint256* program_out = nullptr);

uint256 VoidCoinP2QRSingleProgram(const std::vector<unsigned char>& pubkey);

uint256 VoidCoinP2QRMultisigProgram(
    uint16_t required,
    const std::vector<uint256>& signer_programs);
    
uint256 VoidCoinP2QRMultisigProgram(
    uint16_t required,
    const std::vector<std::vector<unsigned char>>& pubkeys);

bool VoidCoinIsCanonicalP2QRMultisigPolicy(
    uint16_t required,
    const std::vector<std::vector<unsigned char>>& pubkeys,
    std::string* error = nullptr);

bool VoidCoinIsCanonicalP2QRMultisigPolicy(
    uint16_t required,
    const std::vector<uint256>& signer_programs,
    std::string* error = nullptr);

bool VoidCoinParseP2QRMultisigSpend(
    const std::vector<std::vector<unsigned char>>& stack,
    VoidCoinP2QRMultisigSpend& out,
    std::string* error = nullptr);

CScript VoidCoinMakeP2QRScriptPubKey(const uint256& program);

bool VoidCoinIsCanonicalP2QRPush(opcodetype opcode, const std::vector<unsigned char>& data);

bool VoidCoinReadCanonicalP2QRPushes(
    const CScript& script,
    std::vector<std::vector<unsigned char>>& pushes_out,
    std::string* error = nullptr,
    size_t max_pushes = 0);

#endif // VOIDCOIN_SCRIPT_VOIDCOIN_P2QR_H
