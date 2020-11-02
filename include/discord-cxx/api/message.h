#pragma once

#include <vector>
#include <string>
#include <optional>
#include "role.h"
#include "embed.h"
#include "reaction.h"
#include "snowflake.h"
#include "user_info.h"
#include "user_info.h"
#include "timestamp.h"
#include "attachment.h"
#include "guild_member.h"
#include "channel_mention.h"


namespace discord {
    struct Message {
        /**
         * The message id.
        */
        Snowflake id; // id

        /**
         * The id of the channel the message was sent in.
         */
        Snowflake channelId; // channel_id

        /**
         * The id of the guild the message was sent in.
         */
        std::optional<Snowflake> guildId; // guild_id

        // TODO: "(not guaranteed to be a valid user, see below)"
        /**
         * The author of the message.
         */
        UserInfo author; // author

        /**
         * Member properties for this message's author.
         */
        std::optional<GuildMember> member; // member

        /**
         * The contents of the message.
         */
        std::string content; // content

        /**
         * The timestamp at which the message was sent.
         */
        Timestamp timestamp; // timestamp

        /**
         * The timestamp at which the message was edited (null if it was not edited).
         */
        std::optional<Timestamp> editedTimestamp; // edited_timestamp

        /**
         * Specifies whether the message was sent as TTS (Text-To-Speech).
         */
        bool isTts; // tts

        /**
         * Specifies whether the message mentions everyone.
         */
        bool isEveryoneMentioned; // mention_everyone

        // TODO: "array of user objects, with an additional partial member field"
        /**
         * Users specifically mentioned in this message.
         */
        std::vector<UserInfo> mentions; // mentions

        /**
         * Array of mentioned role ids.
         */
        std::vector<Snowflake> mentionedRoles; // mention_roles

        /**
         * Array of mentioned channels.
         */
        std::optional<std::vector<ChannelMention>> mentionedChannels; // mention_channels

        /**
         * Array of attachements.
         */
        std::vector<Attachment> attachments; // attachments

        /**
         * Array of embeds.
         */
        std::vector<Embed> embeds; // embeds

        /**
         * Array of reactions.
         */
        std::optional<std::vector<Reaction>> reactions; // reactions

        // TODO: 'nonce'

        /**
         * Specifies whether this message is pinned.
         */
        bool isPinned; // pinned

        /**
         * If the message was sent by a webhook, this is the webhook's id.
         */
        std::optional<Snowflake> webhookId; // webhook_id

        /**
         * Type of the message.
         */
        MessageType type; // type

        /**
         * The message activity.
         */
        MessageActivity activity;

        /**
         * An application object which is send with
         * Rich Resence-related chat embeds.
         */
        std::optional<MessageApplication> application; // application

        /**
         * A message reference.
         */
        MessageReference messageReference; // message_reference

        /**
         * The message flags.
         */
        MessageFlags flags; // flags
    };

    struct MessageApplication {
        /**
         * The id of the application.
         */
        Snowflake id; // id

        /**
         * The id of the embed's image asset.
         */
        std::optional<std::string> coverImage; // cover_image

        /**
         * The description of the application.
         */
        std::string description; // description

        /**
         * The id of the application's icon.
         */
        std::optional<std::string> icon; // icon

        /**
         * The name of the application.
         */
        std::string name; // name
    };

    struct MessageReference {
        /**
         * The id of the originating message.
         */
        Snowflake id; // message_id

        /**
         * The id of the originating message's channel.
         */
        Snowflake channelId; // channel_id

        /**
         * The id of the orignating message's guild.
         */
        Snowflake guildId; // guild_id
    };

    enum class MessageActivity {
        None,

        Join = 1 << 1,

        Spectate = 1 << 2,

        Listen = 1 << 3,

        JoinRequest = 1 << 5
    };

    enum class MessageFlags {
        None,

        Crossposted = 1 << 0,

        IsCrossposted = 1 << 1,

        SuppressEmbeds = 1 << 2,

        SourceMessageDeleted = 1 << 3,

        Urgent = 1 << 4
    };

    enum class MessageType {
        Default,

        RecipientAdd,

        RecipientRemove,

        Call,

        ChannelNameChange,

        ChannelIconChange,

        ChannelPinnedMessage,

        GuildMemberJoin,

        UserPremiumGuildSubscription,

        UserPremiumGuildSubscriptionTier1,

        UserPremiumGuildSubscriptionTier2,

        UserPremiumGuildSubscriptionTier3,

        ChannelFollowAdd,

        GuildDiscoveryDisqualified,

        GuildDiscoveryRequalified
    };
}
