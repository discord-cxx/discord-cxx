#pragma once

#include <optional>
#include <string>
#include "snowflake.h"

namespace discord {
    struct Attachment {
        /**
         * The id of the attachment.
         */
        Snowflake id; // id

        /**
         * The name of the file
         */
        std::string filename; // filename

        /**
         * The size of the attached file.
         */
        uint32_t size; // size

        /**
         * The source url of the file.
         */
        std::string url; // url

        /**
         * The proxied url of the file.
         */
        std::string proxyUrl; // proxy_url

        /**
         * The height of the file. (image only)
         */
        std::optional<uint16_t> height; // height

        /**
         * The width of the file. (image only)
         */
        std::optional<uint16_t> width; // width
    };
}
