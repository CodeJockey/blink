/*  =========================================================================
    blink - description

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of the Blink Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    blink - 
@discuss
@end
*/

#include "blink.h"

int main (int argc, char *argv [])
{
    bool verbose = false;
    char *iface = NULL;
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-h")) {
            puts ("monitor [options] ...");
            puts ("  --help / -h            this help");
            puts ("  --verbose / -v         verbose test output");
            puts ("  --interface / -i       use this interface");
            return 0;
        }
        if (streq (argv [argn], "--verbose")
        ||  streq (argv [argn], "-v"))
            verbose = true;
        else
        if (streq (argv [argn], "--interface")
        ||  streq (argv [argn], "-i"))
            iface = argv [++argn];
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }
    //  Start LED cycling until Zyre is ready
    blink_led_t *led [3] = { blink_led_new (1), blink_led_new (2), blink_led_new (3) };

/*
    zyre_t *zyre = zyre_new (NULL);
    zsys_info ("Create Zyre node, uuid=%s, name=%s", zyre_uuid (zyre), zyre_name (zyre));
    if (verbose)
        zyre_set_verbose (zyre);
    if (iface)
        zyre_set_interface (zyre, iface);
    zyre_start (zyre);
    zyre_join (zyre, "GLOBAL");
    if (verbose)
        zyre_print (zyre);

    while (true) {
        zyre_event_t *event = zyre_event_new (zyre);
        if (!event)
            break;              //  Interrupted
        if (verbose)
            zyre_event_print (event);

        if (streq (zyre_event_type (event), "ENTER")) {
            //  If new peer, say hello to it and wait for it to answer us
            zsys_info ("[%s] peer entered", zyre_event_peer_name (event));
            zyre_whispers (zyre, zyre_event_peer_uuid (event), "Hello");
        }
        else
        if (streq (zyre_event_type (event), "EXIT")) {
            zsys_info ("[%s] peer exited", zyre_event_peer_name (event));
        }
        else
        if (streq (zyre_event_type (event), "WHISPER")) {
            zsys_info ("[%s] received ping (WHISPER)", zyre_event_peer_name (event));
            zyre_shouts (zyre, "GLOBAL", "Hello");
        }
        else
        if (streq (zyre_event_type (event), "SHOUT")) {
            zsys_info ("[%s](%s) received ping (SHOUT)",
                       zyre_event_peer_name (event), zyre_event_group (event));
        }
        zyre_event_destroy (&event);
    }
    zyre_destroy (&zyre);*/
    return 0;
}
