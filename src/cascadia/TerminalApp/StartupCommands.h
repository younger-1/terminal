// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

#include "NewTerminalArgs.g.h"
#include "NewTabCommand.g.h"
#include "NewPaneCommand.g.h"
#include "FocusTabCommand.g.h"

#include "../../cascadia/inc/cppwinrt_utils.h"
#include "Utils.h"

// TODO: This whole thing is pointless.
// We should really have the parser build ActionAndArgs's, to send to the app
// If there's a param that we want that's not currently in an AaA, then lets update the action's args
// This will work for now

namespace winrt::TerminalApp::implementation
{
    struct NewTerminalArgs : NewTerminalArgsT<NewTerminalArgs>
    {
    public:
        NewTerminalArgs() = default;
        ~NewTerminalArgs() = default;
        GETSET_PROPERTY(winrt::hstring, StartingDirectory, L"");
        GETSET_PROPERTY(winrt::hstring, ProfileName, L"");
        GETSET_PROPERTY(winrt::hstring, Commandline, L"");
    };

    struct NewTabCommand : NewTabCommandT<NewTabCommand>
    {
    public:
        NewTabCommand() = default;
        ~NewTabCommand() = default;
        // GETSET_PROPERTY(winrt::hstring, StartingDirectory, L"");
        GETSET_PROPERTY(winrt::TerminalApp::NewTerminalArgs, TerminalArgs, {});
    };
    struct NewPaneCommand : NewPaneCommandT<NewPaneCommand>
    {
    public:
        NewPaneCommand() = default;
        ~NewPaneCommand() = default;
        GETSET_PROPERTY(winrt::TerminalApp::NewTerminalArgs, TerminalArgs, {});
    };
    struct FocusTabCommand : FocusTabCommandT<FocusTabCommand>
    {
    public:
        FocusTabCommand() = default;
        ~FocusTabCommand() = default;
        GETSET_PROPERTY(Windows::Foundation::IReference<int32_t>, Index, nullptr);
    };

}

namespace winrt::TerminalApp::factory_implementation
{
    BASIC_FACTORY(NewTerminalArgs);
    BASIC_FACTORY(NewTabCommand);
    BASIC_FACTORY(NewPaneCommand);
    BASIC_FACTORY(FocusTabCommand);
}
