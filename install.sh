INSTALL_PATH=~/tileserver-gl/node_modules/@mapbox/mapbox-gl-native
rm -rf $INSTALL_PATH
mkdir -p $INSTALL_PATH/platform/node
cp -rp ./lib $INSTALL_PATH/
cp ./package.json $INSTALL_PATH/
cp platform/node/index.js $INSTALL_PATH/platform/node/
