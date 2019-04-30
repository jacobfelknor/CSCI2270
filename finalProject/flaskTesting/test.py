from flask import Flask
a = Flask(__name__)

@a.route('/')

def home():
    return '{"name":"Lonchera Los Paisas","category":"Mexican","location":"1750 15th St, Boulder, CO 80302, USA","distance":0.388285,"rating":4.8}'


if __name__ == '__main__':
	a.run(debug=True)