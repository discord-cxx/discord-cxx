#pragma once

#include <optional>
#include <vector>
#include <string>
#include "snowflake.h"
#include "timestamp.h"
#include "permission_overwrite.h"
#include "user_info.h"

namespace discord {
    struct Channel {
        /**
         * The id of the channel.
         */
        Snowflake id; // id

        /**
         * The type of the channel.
         */
        uint8_t type; // type

        /**
         * The id of the guild the channel is in. (only if channel is in a guild).
         */
        std::optional<Snowflake> guildId; // guild_id

        /**
         * The position of the channel. (only if channel is in a guild).
         */
        std::optional<uint16_t> position; // position

        /**
         * Array of overwrite objects.
         */
        std::optional<std::vector<PermissionOverwrite>> name;

        /**
         * Name of the channel.
         */
        std::string name; // name

        /**
         * Topic of the channel.
         */
        std::optional<std::string> topic; // topic

        /**
         * Specifies whether the channel is NSFW.
         */
        std::optional<bool> isNsfw; // nsfw

        /**
         * The id of the last message which was sent in this channel.
         */
        std::optional<Snowflake> lastMessageId; // last_message_id

        /**
         * The bitrate of the channel. (voice channel only)
         */
        std::optional<uint32_t> bitrate; // bitrate

        /**
         * The maximum amount of users that can join the channel simultaneously. (voice channel only)
         */
        std::optional<uint8_t> userLimit; // user_limit

        /**
         * The amount of seconds users have to wait before sending another message. (text only)
         */
        std::optional<uint16_t> slowModeDelay; // rate_limit_per_user

        /**
         * Array of recipients. (only for DMs)
         */
        std::optional<std::vector<UserInfo>> recipients; // recipients

        /**
         * The icon hash.
         */
        std::optional<std::string> iconHash; // icon

        /**
         * The id of the owner.
         */
        std::optional<Snowflake> ownerId; // owner_id

        /**
         * Id of the group owner if the owner is a bot.
         */
        std::optional<Snowflake> applicationId; // application_id

        /**
         * Id of the parent category for the channel.
         */
        std::optional<Snowflake> parentId; // parent_id

        /**
         * Time at which the last pinned message was pinned.
         */
        std::optional<Timestamp> lastPinnedAt; // last-pin-timestamp
    };
}