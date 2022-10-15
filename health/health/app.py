from flask import Flask,render_template,url_for,request
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
import joblib
import pickle
import numpy as np
import pandas as pd
import jsonify

app = Flask(__name__)
model = pickle.load(open('model.pkl', 'rb'))

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/predict',methods=['POST'])

def predict():
     
 @app.route('/predict_api',methods=['POST'])
 def predict_api():
    int_features = request.form.get('data')
    final_features=[np.array(int_features)]
    prediction = model.predict(final_features)
    output = round(prediction[0],2)
    return render_template('index.html',)
    return jsonify(output)
if __name__ == "__main__":
    app.run(debug=True)
