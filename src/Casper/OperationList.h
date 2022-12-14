// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Data.h"
#include "proto/Casper.pb.h"
#include "../PrivateKey.h"
#include <string>

namespace TW::Casper {

using TW::Casper::Proto::Operation;

class OperationList {
  public:
    std::string branch;
    std::vector<Operation> operation_list;
    OperationList(const std::string& string);
    void addOperation(const Operation& transaction);
    /// Returns a data representation of the operations.
    Data forge(const PrivateKey& privateKey) const;
    Data forgeBranch() const;
};

} // namespace TW::Tezos
