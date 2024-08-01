// 使用 Webpack 配置来启动一个开发服务器，并设置一些开发相关的选项，比如热模块替换（HMR）和本地服务器的配置。
const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

const webpack = require('webpack');
const webpackDevServer = require('webpack-dev-server');

const config = {
  mode: 'development',
  entry: [
    // 模块热替换的运行时代码
    'webpack/hot/dev-server.js',
    // 用于 web 套接字传输、热重载逻辑的 web server 客户端
    'webpack-dev-server/client/index.js?hot=true&live-reload=true',
    // 你的入口起点
    './src/index.js',
  ],
  devtool: 'inline-source-map',
  plugins: [
    // 模块热替换的插件
    new webpack.HotModuleReplacementPlugin(),
    new HtmlWebpackPlugin({
      title: 'Hot Module Replacement',
    }),
  ],
  output: {
    filename: '[name].bundle.js',
    path: path.resolve(__dirname, 'dist'),
    clean: true,
  },
};
const compiler = webpack(config);

// 由于手动添加了 `hot` 与 `client` 参数，其将被禁用
const server = new webpackDevServer({ hot: false, client: false }, compiler);

(async () => {
  await server.start();
  console.log('dev server 正在运行');
})();