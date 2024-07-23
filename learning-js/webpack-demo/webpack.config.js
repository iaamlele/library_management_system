const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const { title } = require('process');

module.exports = {
    entry: {
        index: './src/index.js',
        print: './src/print.js',
    },
    plugins: [
        new HtmlWebpackPlugin({
            title: '管理输出',
        }),
    ],
    output: {
        filename: '[name].bundle.js',
        path: path.resolve(__dirname, 'dist'),
    },
}