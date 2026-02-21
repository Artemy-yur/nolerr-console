from functions import *

def show_forecast_weather():
    try:
        config = get_data_from_json('config.json')

        if not config:
            print("Config not loaded")
            return

        result = get_weather_json(
                city = config['city'],
                apiKey = config['apiKey'],
                units = config['units'],
                forecast = True,
                lang = config['lang'],
            )

        if not(result):
            return
        
        if str(result.get('cod')) != '200':
            print(f"Response error! Status code: {result.get('cod')}")
            return

        parse_forecast_weather(result)

    except Exception as e:
        print(e)
        return
    
show_forecast_weather()