// Copyright © 2017-2019 Trust.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Casper2/Address.h"
#include "Casper2/Signer.h"
#include "HexCoding.h"
#include "PrivateKey.h"
#include <iostream>
#include <gtest/gtest.h>

namespace TW::Casper2 {

TEST(FilecoinSigner, DerivePublicKey) {
    /*const PrivateKey privateKey(
        parse_hex("1d969865e189957b9824bd34f26d5cbf357fda1a6d844cbf0c9ab1ed93fa7dbe"));*/
    const PrivateKey privateKey(
        parse_hex("954b81a59283ec5bcf7186148f9f8b2f1cdfb62ebbf54652ef6a246d6fcc65f2"));
    //const PublicKey publicKey((privateKey.getPublicKey(TWPublicKeyTypeSECP256k1Extended)));
    const PublicKey publicKey((privateKey.getPublicKey(TWPublicKeyTypeED25519)));
    const Address address(publicKey);
   // ASSERT_EQ(address.string(), "f1z4a36sc7mfbv4z3qwutblp2flycdui3baffytbq");
    ASSERT_EQ(address.string(), "0152a685e0edd9060da4a0d52e500d65e21789df3cbfcb878c91ffeaea756d1c53");
    std::cout<<"string address is"<<address.string()<<std::endl;
}

TEST(FilecoinSigner, Sign) {
    const PrivateKey privateKey(
        parse_hex("1d969865e189957b9824bd34f26d5cbf357fda1a6d844cbf0c9ab1ed93fa7dbe"));
//    const PublicKey publicKey((privateKey.getPublicKey(TWPublicKeyTypeSECP256k1Extended)));
    const PublicKey publicKey((privateKey.getPublicKey(TWPublicKeyTypeED25519)));
    const Address fromAddress(publicKey);
    const Address toAddress("f1rletqqhinhagw6nxjcr4kbfws25thgt7owzuruy");

    Transaction tx(toAddress, fromAddress,
                   /*nonce*/ 1,
                   /*value*/ 6000,
                   /*gasLimit*/ 23423423423423,
                   /*gasFeeCap*/ 456456456456445645,
                   /*gasPremium*/ 5675674564734345);

    Data signature = Signer::sign(privateKey, tx);

    ASSERT_EQ(tx.serialize(signature), R"({"Message":{"From":"f1z4a36sc7mfbv4z3qwutblp2flycdui3baffytbq","GasFeeCap":"456456456456445645","GasLimit":23423423423423,"GasPremium":"5675674564734345","Nonce":1,"To":"f1rletqqhinhagw6nxjcr4kbfws25thgt7owzuruy","Value":"6000"},"Signature":{"Data":"3GOUpn2Wiwe20QXLC8ixx23WiKDwrVkfxYi3CgzZ5jBVKZT4WUOZNuZhpUFky0PqGaM7vErEOi//yqBGSIQQUAA=","Type":1}})");
}

} // namespace TW::Filecoin
