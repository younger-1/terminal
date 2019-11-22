// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#include "pch.h"
#include <WexTestClass.h>

#include "consoletaeftemplates.hpp"
#include "../WindowsTerminal/AppCommandline.h"
// #include <winrt/TerminalApp.h>

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
        {
            wchar_t* rawCommands[]{ L"wt.exe" };
            auto commandlines = AppCommandline::BuildCommands(1, rawCommands);
            VERIFY_ARE_EQUAL(1u, commandlines.size());
            VERIFY_ARE_EQUAL(1u, commandlines.at(0).argc());
        }
        {
            wchar_t* rawCommands[]{ L"wt.exe", L"an arg with spaces" };

            auto commandlines = AppCommandline::BuildCommands(1, rawCommands);
            VERIFY_ARE_EQUAL(1u, commandlines.size());
            VERIFY_ARE_EQUAL(2u, commandlines.at(0).argc());
        }
    }
}
