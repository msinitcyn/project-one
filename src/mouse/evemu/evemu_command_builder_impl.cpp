#include <format>
#include <string>

#include "mouse/evemu/evemu_command_builder_impl.h"

using std::string;
using std::format;

string ProjectOne::Mouse::Evemu::EvemuCommandBuilderImpl::Build(string event, int type, int code, int value) {

    return format("evemu-event /dev/input/{} --type {} --code {} --value {}", event, type, code, value);
}

