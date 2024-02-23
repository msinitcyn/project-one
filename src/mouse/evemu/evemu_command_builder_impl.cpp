#include <fmt/format.h>
#include <string>

#include "mouse/evemu/evemu_command_builder_impl.h"

using std::string;

string ProjectOne::Mouse::Evemu::EvemuCommandBuilderImpl::build(string event, int type, int code, int value) {

    return fmt::format("evemu-event /dev/input/{} --type {} --code {} --value {}", event, type, code, value);
}

