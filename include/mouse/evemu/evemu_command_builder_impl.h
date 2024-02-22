// evemu_command_builder_impl.h
#pragma once

#include <string>
#include "evemu_command_builder.h"

namespace ProjectOne::Mouse::Evemu {
    class EvemuCommandBuilderImpl : public EvemuCommandBuilder {
    public:
        std::string build(std::string event, int type, int code, int value) override;

        ~EvemuCommandBuilderImpl() override {
        }
    };
}
