#!/bin/sh

# Check Number of Arguments
if [[ "$#" -ne 2 ]]; then
    echo "Usage: $0 {conf|conf-build|conf-run} {debug|release}"
    echo "Usage: $0 {build|run}"
    exit 1
fi

command=$1
configuration=$2

# Verify parameters
if [[ "$command" != "build" && "$command" != "run" && "$command" != "conf" && "$command" != "conf-build" && "$command" != "conf-run" ]]; then
    echo "Error: The first parameter must be 'build', 'run', 'conf', 'conf-build', 'conf-run'"
    exit 1
fi

if [[ "$configuration" != "debug" && "$configuration" != "release" ]]; then
    echo "Error: The second parameter must be 'debug', 'release'"
    exit 1
fi


project_name=$(grep "project(" meson.build | head -1 | sed -n "s/^project('\([^']*\)'.*/\1/p")

# Command execution
if [[ "$command" == "build" || "$command" == "run" ]]; then
    case "$command" in
        build)
            case "$configuration" in
                debug)
                    meson compile -C build-debug
                    ;;
                release)
                    meson compile -C build-release
                    ;;
            esac
            ;;
        run)
            case "$configuration" in
                debug)
                    meson compile -C build-debug
                    ./build-debug/$project_name
                    ;;
                release)
                    meson compile -C build-release
                    ./build-release/$project_name
                    ;;
            esac
            ;;
    esac
else
    case "$command" in
        conf)
            case "$configuration" in
                debug)
                    meson setup --buildtype debug build-debug
                    ;;
                release)
                    meson setup --buildtype release build-release
                    ;;
            esac
            ;;
        conf-build)
            case "$configuration" in
                debug)
                    meson setup --buildtype debug build-debug
                    meson compile -C build-debug
                    ;;
                release)
                    meson setup --buildtype release build-release
                    meson compile -C build-release
                    ;;
            esac
            ;;
        conf-run)
            case "$configuration" in
                debug)
                    meson setup --buildtype debug build-debug
                    meson compile -C build-debug
                    ./build-debug/$project_name
                    ;;
                release)
                    meson setup --buildtype release build-release
                    meson compile -C build-release
                    ./build-release/$project_name
                    ;;
            esac
            ;;
    esac
fi
