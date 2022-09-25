// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here MAY BE LOST.
// Generated one-time (codegen/bin/cointests)
//

#include "../interface/TWTestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>

TEST(TWCasper2CoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeCasper2));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("bafy2bzacedsgjcd6xfhrrymmfrqubb44otlyhvgqkgsh533d5j5hwniiqespm"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeCasper2, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("f1abjxfbp274xpdqcpuaykwkfb43omjotacm2p3za"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeCasper2, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeCasper2));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeCasper2));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeCasper2), 18);
    ASSERT_EQ(TWBlockchainFilecoin, TWCoinTypeBlockchain(TWCoinTypeCasper2));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeCasper2));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeCasper2));
    assertStringsEqual(symbol, "CSPR2");
    assertStringsEqual(txUrl, "https://filfox.info/en/message/bafy2bzacedsgjcd6xfhrrymmfrqubb44otlyhvgqkgsh533d5j5hwniiqespm");
    assertStringsEqual(accUrl, "https://filfox.info/en/address/f1abjxfbp274xpdqcpuaykwkfb43omjotacm2p3za");
    assertStringsEqual(id, "casper2");
    assertStringsEqual(name, "Casper2");
}
