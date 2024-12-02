#!/bin/bash

RESET="\033[0m"
BOLD="\033[1m"
GREEN="\033[32m"
YELLOW="\033[33m"
RED="\033[31m"

SCENES_DIR="src/Display/Scene/Scenes"
TEMPLATE_DIR=$SCENES_DIR/TEMPLATE

function capitalize {
    echo $1 | awk '{print toupper(substr($0,1,1))tolower(substr($0,2))}'
}

function uppercase {
    echo $1 | awk '{print toupper($0)}'
}

if [ $# -eq 0 ]; then
    echo -e $BOLD$YELLOW"Usage: createScene.sh <SceneName>"$RESET
    exit 1
fi

if [ -z "$1" ]; then
    echo -e $BOLD$RED"Error: Scene name cannot be empty"$RESET
    exit 1
fi

if [ ! -d "src/Display/Scene/Scenes" ]; then
    echo -e $BOLD$RED"Error: Scene directory not found"$RESET
    exit 1
fi

if [ ! -d "src/Display/Scene/Scenes/TEMPLATE" ]; then
    echo -e $BOLD$RED"Error: Template scene not found"$RESET
    exit 1
fi

NEW_SCENE_NAME=$(capitalize $1)

if [ $NEW_SCENE_NAME == "Template" ]; then
    echo -e $BOLD$RED"Error: Scene name cannot be 'Template'"$RESET
    exit 1
fi

if [ -d "src/Display/Scene/Scenes/$NEW_SCENE_NAME" ]; then
    echo -e $BOLD$RED"Error: Scene $NEW_SCENE_NAME already exists"$RESET
    exit 1
fi


echo -e $BOLD$GREEN" >> Creating scene $NEW_SCENE_NAME..."$RESET
cp -r $TEMPLATE_DIR $SCENES_DIR/$NEW_SCENE_NAME

mv $SCENES_DIR/$NEW_SCENE_NAME/TEMPLATEScene.hpp $SCENES_DIR/$NEW_SCENE_NAME/$(echo $NEW_SCENE_NAME)Scene.hpp
mv $SCENES_DIR/$NEW_SCENE_NAME/TEMPLATEScene.cpp $SCENES_DIR/$NEW_SCENE_NAME/$(echo $NEW_SCENE_NAME)Scene.cpp

sed -i "s/RTYPE_DISPLAY_SCENE_TEMPLATE_HPP_/RTYPE_DISPLAY_SCENE_$(uppercase $NEW_SCENE_NAME)_HPP_/g" $SCENES_DIR/$NEW_SCENE_NAME/$(echo $NEW_SCENE_NAME)Scene.hpp
sed -i "s/TEMPLATE/$NEW_SCENE_NAME/g" $SCENES_DIR/$NEW_SCENE_NAME/$(echo $NEW_SCENE_NAME)Scene.hpp
sed -i "s/TEMPLATE/$NEW_SCENE_NAME/g" $SCENES_DIR/$NEW_SCENE_NAME/$(echo $NEW_SCENE_NAME)Scene.cpp

echo -e $BOLD$GREEN" >> Scene $NEW_SCENE_NAME created!"$RESET
