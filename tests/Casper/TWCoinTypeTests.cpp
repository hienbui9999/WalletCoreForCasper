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


TEST(TWCasperCoinType, TWCoinType) {
	
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeCasper));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("onk3Z6V4StyfiXTPSHwZFvTKVAaws37cHmZacmULPr3VbVHpKrg"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeCasper, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("tz1SiPXX4MYGNJNDsRc7n8hkvUqFzg8xqF9m"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeCasper, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeCasper));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeCasper));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeCasper), 6);
    ASSERT_EQ(TWBlockchainTezos, TWCoinTypeBlockchain(TWCoinTypeCasper));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeCasper));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeCasper));
    assertStringsEqual(symbol, "CSPR");
    assertStringsEqual(txUrl, "https://tzstats.com/onk3Z6V4StyfiXTPSHwZFvTKVAaws37cHmZacmULPr3VbVHpKrg");
    assertStringsEqual(accUrl, "https://tzstats.com/tz1SiPXX4MYGNJNDsRc7n8hkvUqFzg8xqF9m");
    assertStringsEqual(id, "casper");
    assertStringsEqual(name, "Casper");
}
