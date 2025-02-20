/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#pragma once

namespace WPEFramework {
namespace TestCore {

    class TestLifeCycle {
    public:
        TestLifeCycle() = delete;
        TestLifeCycle(const TestLifeCycle& a_Copy) = delete;
        TestLifeCycle& operator=(const TestLifeCycle& a_RHS) = delete;

    public:
        TestLifeCycle(const TCHAR formatter[], ...)
        {
            va_list ap;
            va_start(ap, formatter);
            Core::Format(_text, formatter, ap);
            va_end(ap);
        }
        explicit TestLifeCycle(const string& text)
            : _text(Core::ToString(text))
        {
        }
        ~TestLifeCycle() = default;

    public:
        inline const char* Data() const { return (_text.c_str()); }
        inline uint16_t Length() const { return (static_cast<uint16_t>(_text.length())); }

    private:
        std::string _text;
    };

    class TestOutput {
    public:
        TestOutput() = delete;
        TestOutput(const TestOutput& a_Copy) = delete;
        TestOutput& operator=(const TestOutput& a_RHS) = delete;

    public:
        TestOutput(const TCHAR formatter[], ...)
        {
            va_list ap;
            va_start(ap, formatter);
            Core::Format(_text, formatter, ap);
            va_end(ap);
        }
        explicit TestOutput(const string& text)
            : _text(Core::ToString(text))
        {
        }
        ~TestOutput() = default;

    public:
        inline const char* Data() const { return (_text.c_str()); }
        inline uint16_t Length() const { return (static_cast<uint16_t>(_text.length())); }

    private:
        std::string _text;
    };

} // namespace TestCore
} // namespace WPEFramework
