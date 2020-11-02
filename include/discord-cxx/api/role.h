#pragma once

#include <string>
#include "snowflake.h"

namespace discord {
    struct Role {
        /**
         * The role's id.
         */
        Snowflake id; // id

        /**
         * The role's name.
         */
        std::string name; // name

        /**
         * The role's color.
         */
        uint32_t color; // color

        /**
         * Specifies whether the role is pinned to the user listing.
         */
        bool isHoisted; // hoist

        /**
         * Position of the role in the server.
         */
        uint8_t position; // position

        /**
         * Bit set of role's permissions.
         */
        std::string permissions; // permissions

        /**
         * Specifies whether the role is managed by an integration.
         */
        bool isManaged; // managed

        /**
         * Specifies whether the role is mentionable.
         */
        bool isMentionable; // mentionable
    };
}