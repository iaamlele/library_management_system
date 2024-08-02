// 定义了项目如何打包和处理不同类型的资源。
const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  mode: 'development',
  entry: {
    app: './src/index.js',
  },
  devtool: 'inline-source-map',
  devServer: {
    static: './dist',
    hot: true,
  },

 module: {
   rules: [
     {
       test: /\.css$/,
       use: ['style-loader', 'css-loader'],
     },
   ],
 },
  plugins: [
    new HtmlWebpackPlugin({
      title: 'js simulates jquery',
    }),
  ],
  output: {
    filename: 'jq-webpack.js',
    path: path.resolve(__dirname, 'dist'),
    clean: true,
    library: {
        name: 'jq',
        type: 'umd',
    },
  },
  externals: {
    lodash: {   
      commonjs: 'lodash',   
      commonjs2: 'lodash',   
      amd: 'lodash',   
      root: '_',   
    },   
  },
};