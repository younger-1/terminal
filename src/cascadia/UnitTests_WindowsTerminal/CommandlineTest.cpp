// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#include "precomp.h"
#include <WexTestClass.h>

#include "consoletaeftemplates.hpp"
#include "../WindowsTerminal/AppCommandline.h"
#include <winrt/TerminalApp.h>

using namespace WEX::Logging;
using namespace WEX::TestExecution;

using namespace winrt::TerminalApp;

namespace WindowsTerminalUnitTests
{
    class CommandlineTest
    {
        TEST_CLASS(CommandlineTest);
        TEST_METHOD(TryCreateWinRTType);
        TEST_METHOD(ParseSimmpleCommandline);
    };

    void CommandlineTest::TryCreateWinRTType()
    {
        ActionAndArgs newTabAction{};
        VERIFY_ARE_NOT_EQUAL(ShortcutAction::NewTab, newTabAction.Action());

        newTabAction.Action(ShortcutAction::NewTab);
        newTabAction.Args(NewTabArgs{});

        VERIFY_ARE_EQUAL(ShortcutAction::NewTab, newTabAction.Action());
    }

    void CommandlineTest::ParseSimmpleCommandline()
    {
        VERIFY_IS_TRUE(false);
    }
}
